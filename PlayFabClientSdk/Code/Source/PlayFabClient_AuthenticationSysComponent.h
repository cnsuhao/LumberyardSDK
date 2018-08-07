
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabClientSdk/PlayFabClient_AuthenticationBus.h>

namespace PlayFabClientSdk
{
    class PlayFabClient_AuthenticationSysComponent
        : public AZ::Component
        , protected PlayFabClient_AuthenticationRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabClient_AuthenticationSysComponent, "{}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabClient_AuthenticationRequestBus interface implementation

        // ------------ Generated Api calls
        void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
