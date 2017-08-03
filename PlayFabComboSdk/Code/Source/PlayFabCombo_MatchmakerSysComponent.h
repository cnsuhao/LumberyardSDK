
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboSdk/PlayFabCombo_MatchmakerBus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_MatchmakerSysComponent
        : public AZ::Component
        , protected PlayFabCombo_MatchmakerRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabCombo_MatchmakerSysComponent, "{525A86F9-CFF4-4868-A55F-24F5E76823CC}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabCombo_MatchmakerRequestBus interface implementation

        // ------------ Generated Api calls
        void AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
