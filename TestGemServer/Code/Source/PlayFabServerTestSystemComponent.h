
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabServerTest/PlayFabServerTestBus.h>

namespace PlayFabServerTest
{
    class PlayFabServerTestSystemComponent
        : public AZ::Component
        , protected PlayFabServerTestRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabServerTestSystemComponent, "{5AB613A1-8AA2-4099-AFAB-F43CACC66A60}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabServerTestRequestBus interface implementation

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
