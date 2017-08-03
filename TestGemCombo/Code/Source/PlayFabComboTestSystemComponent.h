
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboTest/PlayFabComboTestBus.h>

namespace PlayFabComboTest
{
    class PlayFabComboTestSystemComponent
        : public AZ::Component
        , protected PlayFabComboTestRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabComboTestSystemComponent, "{B7AF3C21-D689-4A83-86F5-00EA210D0A22}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabComboTestRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////

        void LoginOrRegister();
    };
}
