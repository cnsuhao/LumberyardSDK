
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabClientTest/PlayFabClientTestBus.h>

namespace PlayFabClientTest
{
    class PlayFabClientTestSystemComponent
        : public AZ::Component
        , protected PlayFabClientTestRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabClientTestSystemComponent, "{71FD0DA7-A873-4672-A46F-D0A2FD686FA5}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabClientTestRequestBus interface implementation

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
