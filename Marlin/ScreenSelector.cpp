#include "ScreenSelector.h"

namespace screen
{
	ScreenSelector::ScreenSelector(const char * title)
		: Screen(SELECTOR, title)
	{
	}

	ScreenSelector::~ScreenSelector()
	{
	}

	void ScreenSelector::left()
	{
		if (m_select == 0)
		{
			m_select = 0;
		}
		else
		{
			--m_select;
		}
	}

	void ScreenSelector::right()
	{
		++m_select;
	}

	void ScreenSelector::draw()
	{
		SERIAL_ECHO(m_title);
		SERIAL_ECHO("  < ");
		SERIAL_ECHO(m_select);
		SERIAL_ECHOLN(" >  ");
	}

	Screen & ScreenSelector::press()
	{
		return * m_next_screen;
	}

   void ScreenSelector::add(Screen & component)
   {
      m_next_screen = &component;
   }
}