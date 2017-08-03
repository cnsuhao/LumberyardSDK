
#include "StdAfx.h"
#include <platform_impl.h>

#include "PlayFabComboTestSystemComponent.h"

#include <FlowSystem/Nodes/FlowBaseNode.h>
#include <IGem.h>

namespace PlayFabComboTest
{
    class PlayFabComboTestModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(PlayFabComboTestModule, "{0757A088-EC2D-4417-9F45-FB1DF16A80E6}", CryHooksModule);

        PlayFabComboTestModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PlayFabComboTestSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PlayFabComboTestSystemComponent>(),
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
AZ_DECLARE_MODULE_CLASS(PlayFabComboTest_fee877ce92be40deb14badcc4b93b6ff, PlayFabComboTest::PlayFabComboTestModule)
