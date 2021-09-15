#pragma once

#include <stack>
#include <memory>
#include "State.h"

namespace Engine
{
	class StateManager
	{
	private:
		std::stack<std::unique_ptr<State>> m_stateStack;
		std::unique_ptr<State> m_newState;

		bool m_add;
		bool m_replace;
		bool m_remove;
	public:
		StateManager();
		~StateManager();

		void add(std::unique_ptr<State> toadd, bool replace = false);
		void popCurrent();
		void procesStateChange();
		std::unique_ptr<State>& getCurrent();
	};
}


