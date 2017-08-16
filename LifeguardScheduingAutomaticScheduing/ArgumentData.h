﻿#pragma once

#include <iostream>

namespace Fuookami
{
	/*!
	*	\类名 	ArgumentData
	*
	*	\说明 	复杂类构造参数限制器模板
	*			用以在调用复杂类构造函数、构造方法或初始化方法时强制参数进行显示转型确保参数正确
	*			使用方法为声明参数类为该模板类的一个特例化类，其特例化类参数为该参数的实际数据类型
	*			并提供唯一的带有explicit声明的构造函数以强制其进行显式转型确保参数正确
	*			例如要声明一个实际数据类型为int的参数类ArgClass，则作以下声明：
	*
	*			class ArgClass : public ArgumentData<int>
	*			{
	*			public:
	*				explicit ArgClass(const int data) : ArgumentData<int>(data) {};
	*			}
	*
	*			然后将该类作为复杂类构造函数的参数即可
	*/
	template <typename T>
	class ArgumentData
	{
	public:
		ArgumentData(const T &data) : m_data(data) {};
		ArgumentData(const ArgumentData &ano) : m_data(ano.m_data) {};
		ArgumentData(const ArgumentData &&ano) : m_data(ano.m_data) {};
		~ArgumentData() {};

		template <typename U>
		ArgumentData &operator=(const ArgumentData<U> &rop) { m_data = rop.m_data; return *this; }
		template <typename U>
		ArgumentData &operator=(const U &rop) { m_data = rop; return *this; }
		template <typename U>
		ArgumentData &operator=(const ArgumentData<U> &&rop) { m_data = rop.m_data; return *this; }
		template <typename U>
		ArgumentData &operator=(const U &&rop) { m_data = rop; return *this; }

		template <typename U>
		ArgumentData operator+(const ArgumentData<U> &rop) { return ArgumentData(m_data + rop.m_data); }
		template <typename U>
		ArgumentData operator+(const U &rop) { return ArgumentData(m_data + rop); }
		template <typename U>
		ArgumentData &operator+=(const ArgumentData<U> &rop) { m_data += rop.m_data; return *this; }
		template <typename U>
		ArgumentData &operator+=(const U &rop) { m_data += rop; return *this; }

		template <typename U>
		ArgumentData operator-(const ArgumentData<U> &&rop) { return ArgumentData(m_data - rop.m_data); }
		template <typename U>
		ArgumentData operator-(const U &rop) { return ArgumentData(m_data - rop); }
		template <typename U>
		ArgumentData &operator-=(const ArgumentData<U> &&rop) { m_data -= rop.m_data; return *this; }
		template <typename U>
		ArgumentData &operator-=(const U &rop) { m_data -= rop; return *this; }

		template <typename U>
		ArgumentData operator*(const ArgumentData<U> &rop) { return ArgumentData(m_data * rop.m_data); }
		template <typename U>
		ArgumentData operator*(const U &rop) { return ArgumentData(m_data * rop); }
		template <typename U>
		ArgumentData &operator*=(const ArgumentData<U> &rop) { m_data *= rop.m_data; return *this; }
		template <typename U>
		ArgumentData &operator*=(const U &rop) { m_data *= rop; return *this; }

		template <typename U>
		ArgumentData operator/(const ArgumentData<U> &&rop) { return ArgumentData(m_data / rop.m_data); }
		template <typename U>
		ArgumentData operator/(const U &rop) { return ArgumentData(m_data / rop); }
		template <typename U>
		ArgumentData &operator/=(const ArgumentData<U> &&rop) { m_data /= rop.m_data; return *this; }
		template <typename U>
		ArgumentData &operator/=(const U &rop) { m_data /= rop; return *this; }

		template <typename U>
		ArgumentData operator%(const ArgumentData<U> &&rop) { return ArgumentData(m_data % rop.m_data); }
		template <typename U>
		ArgumentData operator%(const U &rop) { return ArgumentData(m_data % rop); }
		template <typename U>
		ArgumentData &operator%=(const ArgumentData<U> &&rop) { m_data %= rop.m_data; return *this; }
		template <typename U>
		ArgumentData &operator%=(const U &rop) { m_data %= rop; return *this; }

		inline T &data() { return m_data; }
		inline const T &data() const { return m_data; }

	private:
		T m_data;
	};
}

template <typename T>
std::istream &operator>>(std::istream &is, const Fuookami::ArgumentData<T> &data) { is >> data.data(); return is; }
template <typename T>
std::ostream &operator<<(std::ostream &os, const Fuookami::ArgumentData<T> &data) { os << data.data(); return os; }

template <typename T, typename U>
bool operator==(const Fuookami::ArgumentData<T> &lop, const Fuookami::ArgumentData<U> &rop) { return lop.data() == rop.data(); }
template <typename T, typename U>
bool operator==(const Fuookami::ArgumentData<T> &lop, const U &rop) { return lop.data() == rop; }
template <typename T, typename U>
bool operator==(const U &lop, const Fuookami::ArgumentData<T> &rop) { return lop == rop.data(); }

template <typename T, typename U>
bool operator!=(const Fuookami::ArgumentData<T> &lop, const Fuookami::ArgumentData<U> &rop) { return lop.data() != rop.data(); }
template <typename T, typename U>
bool operator!=(const Fuookami::ArgumentData<T> &lop, const U &rop) { return lop.data() != rop; }
template <typename T, typename U>
bool operator!=(const U &lop, const Fuookami::ArgumentData<T> &rop) { return lop != rop.data(); }

template <typename T, typename U>
bool operator<(const Fuookami::ArgumentData<T> &lop, const Fuookami::ArgumentData<U> &rop) { return lop.data() < rop.data(); }
template <typename T, typename U>
bool operator<(const Fuookami::ArgumentData<T> &lop, const U &rop) { return lop.data() < rop; }
template <typename T, typename U>
bool operator<(const U &lop, const Fuookami::ArgumentData<T> &rop) { return lop < rop.data(); }

template <typename T, typename U>
bool operator>(const Fuookami::ArgumentData<T> &lop, const Fuookami::ArgumentData<U> &rop) { return lop.data() > rop.data(); }
template <typename T, typename U>
bool operator>(const Fuookami::ArgumentData<T> &lop, const U &rop) { return lop.data() > rop; }
template <typename T, typename U>
bool operator>(const U &lop, const Fuookami::ArgumentData<T> &rop) { return lop > rop.data(); }

template <typename T, typename U>
bool operator<=(const Fuookami::ArgumentData<T> &lop, const Fuookami::ArgumentData<U> &rop) { return lop.data() <= rop.data(); }
template <typename T, typename U>
bool operator<=(const Fuookami::ArgumentData<T> &lop, const U &rop) { return lop.data() <= rop; }
template <typename T, typename U>
bool operator<=(const U &lop, const Fuookami::ArgumentData<T> &rop) { return lop <= rop.data(); }

template <typename T, typename U>
bool operator>=(const Fuookami::ArgumentData<T> &lop, const Fuookami::ArgumentData<U> &rop) { return lop.data() >= rop.data(); }
template <typename T, typename U>
bool operator>=(const Fuookami::ArgumentData<T> &lop, const U &rop) { return lop.data() >= rop; }
template <typename T, typename U>
bool operator>=(const U &lop, const Fuookami::ArgumentData<T> &rop) { return lop >= rop.data(); }

template <typename T, typename U>
T operator+(const T &lop, const Fuookami::ArgumentData<U> &rop) { return T(lop + rop.data()); }
template <typename T, typename U>
T operator-(const T &lop, const Fuookami::ArgumentData<U> &rop) { return T(lop - rop.data()); }
template <typename T, typename U>
T operator*(const T &lop, const Fuookami::ArgumentData<U> &rop) { return T(lop * rop.data()); }
template <typename T, typename U>
T operator/(const T &lop, const Fuookami::ArgumentData<U> &rop) { return T(lop / rop.data()); }
template <typename T, typename U>
T operator%(const T &lop, const Fuookami::ArgumentData<U> &rop) { return T(lop % rop.data()); }