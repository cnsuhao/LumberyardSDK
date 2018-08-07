
#pragma once

#include <PlayFabComboSdk/PlayFabError.h>
#include <PlayFabComboSdk/PlayFabAuthenticationDataModels.h>
#include <AzCore/EBus/EBus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_AuthenticationRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual int GetPendingCalls() = 0;

        // ------------ Generated API call wrappers
        virtual void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
    };

    using PlayFabCombo_AuthenticationRequestBus = AZ::EBus<PlayFabCombo_AuthenticationRequests>;
} // namespace PlayFabComboSdk
