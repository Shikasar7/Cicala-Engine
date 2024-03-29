#pragma once

#include "Cicala/Core/Core.h"
#include "Cicala/Core/Timestep.h"
#include "Cicala/Events/Event.h"

namespace Cicala {

	class CICALA_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() ;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender(){}

		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}