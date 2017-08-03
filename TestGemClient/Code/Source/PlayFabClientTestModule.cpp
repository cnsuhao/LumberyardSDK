
#include "StdAfx.h"
#include <platform_impl.h>

#include "PlayFabClientTestSystemComponent.h"

#include <FlowSystem/Nodes/FlowBaseNode.h>
#include <IGem.h>

namespace PlayFabClientTest
{
    class PlayFabClientTestModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(PlayFabClientTestModule, "{866F12CD-AADA-4B57-932B-123B3B14E59F}", CryHooksModule);

        PlayFabClientTestModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PlayFabClientTestSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PlayFabClientTestSystemComponent>(),
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
AZ_DECLARE_MODULE_CLASS(PlayFabClientTest_a283c61c3bb84efbb6bfbd04c9b2f0d0, PlayFabClientTest::PlayFabClientTestModule)
