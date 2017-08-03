
#pragma once

#include <PlayFabServerSdk/PlayFabError.h>
#include <PlayFabServerSdk/PlayFabMatchmakerDataModels.h>
#include <AzCore/EBus/EBus.h>

namespace PlayFabServerSdk
{
    class PlayFabServer_MatchmakerRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual int GetPendingCalls() = 0;

        // ------------ Generated API call wrappers
        virtual void AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
    };

    using PlayFabServer_MatchmakerRequestBus = AZ::EBus<PlayFabServer_MatchmakerRequests>;
} // namespace PlayFabServerSdk
