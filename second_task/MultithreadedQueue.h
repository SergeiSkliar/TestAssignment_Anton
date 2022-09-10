#include <thread>
#include <queue>
#include <mutex>
#include <memory>

template<typename T>
class MultithreadedQueue
{
private:
	mutable std::mutex mut;
	std::condition_variable cond_var;
public:
	std::queue<T> data_queue; // вынес в public для упрощения тестирования

	MultithreadedQueue() {}
	MultithreadedQueue(MultithreadedQueue const& other)
	{
		std::lock_guard<std::mutex> lk(other.mut);
		data_queue = other.data_queue;
	}
	void push(T new_value)
	{
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(std::move(new_value));
		cond_var.notify_one();
	}
	void pop(T& value)
	{
		std::unique_lock<std::mutex> lk(mut);
		cond_var.wait(lk, [this] {return !data_queue.empty(); });
		value = std::move(data_queue.front());
		data_queue.pop();
	}
	std::shared_ptr<T> pop()
	{
		std::unique_lock<std::mutex> lk(mut);
		cond_var.wait(lk, [this] {return !data_queue.empty(); });
		std::shared_ptr<T> res(
			std::make_shared<T>(std::move(data_queue.front())));
		data_queue.pop();
		return res;
	}
	bool empty() const
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.empty();
	}
};
