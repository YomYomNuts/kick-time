#include <map>
#include <vector>

using namespace std;

template <class T, class U>
class create_map
{
private:
	map<T,U> m_map;
public:
	create_map(const T& key, const U& val)
	{
		m_map[key] = val;
	}

	create_map<T, U>& operator()(const T& key, const U& val)
	{
		m_map[key] = val;
		return *this;
	}

	operator map<T,U>()
	{
		return m_map;
	}
};

template <class T>
class create_vector
{
private:
	vector<T> m_vector;
public:
	create_vector(const T& val)
	{
		m_vector.push_back(val);
	}

	create_vector<T>& operator()(const T& val)
	{
		m_vector.push_back(val);
		return *this;
	}

	operator vector<T>()
	{
		return m_vector;
	}
};