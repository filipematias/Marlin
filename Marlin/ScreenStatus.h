#ifndef SCREEN_STATUS_H
#define SCREEN_STATUS_H


#include <stdint.h>
#include "Screen.h"
#include "Observer.h"
#include "Functor.h"

namespace screen
{
	template <typename T, typename R, typename... Args >
		class ScreenStatus : public Screen, public Observer<T>, public Functor<R, Args...>
	{
		public:
			ScreenStatus(const char * title = 0, typename Functor<R, Args...>::FuncPtr fptr = do_nothing, Subject<T> * model = 0);
			virtual ~ScreenStatus();

			void icon(Icon & component);
			Icon & icon();

			void update(T value);

		private:
			Icon * m_icon_alternate;
			uint8_t m_icon_index;
	};

	template <typename T, typename R, typename... Args >
	ScreenStatus<T, R, Args...>::ScreenStatus(const char * title,  typename Functor<R, Args...>::FuncPtr fptr, Subject<T> * model)
		: Screen(title, STATUS, do_nothing)
		, Functor<R, Args...>(fptr)
		, Observer<T>(model)
		, m_icon_index(0)
	{ }

	template <typename T, typename R, typename... Args >
	ScreenStatus<T, R, Args...>::~ScreenStatus()
	{ }

	template <typename T, typename R, typename... Args >
	void ScreenStatus<T, R, Args...>::icon(Icon & component)
	{
		if (m_icon_index < 1)
		{
			m_icon = &component;
		}
		else
		{
			m_icon_alternate = &component;
		}
		++m_icon_index;
	}

	template <typename T, typename R, typename... Args >
	Icon & ScreenStatus<T, R, Args...>::icon()
	{
		return * m_icon;
	}

	template <typename T, typename R, typename... Args >
	void ScreenStatus<T, R, Args...>::update(T value) 
	{ }
}

#endif //SCREEN_STATUS_H