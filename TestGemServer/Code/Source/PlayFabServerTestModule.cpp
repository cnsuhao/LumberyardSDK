
#include "StdAfx.h"
#include <platform_impl.h>

#include "PlayFabServerTestSystemComponent.h"

#include <FlowSystem/Nodes/FlowBaseNode.h>
#include <IGem.h>

namespace PlayFabServerTest
{
    class PlayFabServerTestModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(PlayFabServerTestModule, "{A16750F6-EA08-4E1E-BA74-400BBECF9606}", CryHooksModule);

        PlayFabServerTestModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PlayFabServerTestSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PlayFabServerTestSystemComponent>(),
            };
        }

        
        void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override
        {
            switch (event)
            {
            case ESYSTEM_EVENT_FLOW_SYSTEM_REGISTER_EXTERNAL_NODES:
                RegisterExternalFlowNodes();
                break;
            }
        }

    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(PlayFabServerTest_1ef0cc192c26498e9d87e5940d0f0154, PlayFabServerTest::PlayFabServerTestModule)
