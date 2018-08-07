
#pragma once

#include <PlayFabClientSdk/PlayFabError.h>
#include <PlayFabClientSdk/PlayFabProfilesDataModels.h>
#include <AzCore/EBus/EBus.h>

namespace PlayFabClientSdk
{
    class PlayFabClient_ProfilesRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual int GetPendingCalls() = 0;

        // ------------ Generated API call wrappers
        virtual void GetGlobalPolicy(ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetProfile(ProfilesModels::GetEntityProfileRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfileResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetProfiles(ProfilesModels::GetEntityProfilesRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SetGlobalPolicy(ProfilesModels::SetGlobalPolicyRequest& request, ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SetProfileLanguage(ProfilesModels::SetProfileLanguageRequest& request, ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SetProfilePolicy(ProfilesModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
    };

    using PlayFabClient_ProfilesRequestBus = AZ::EBus<PlayFabClient_ProfilesRequests>;
} // namespace PlayFabClientSdk
