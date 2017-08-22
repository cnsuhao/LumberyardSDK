
#pragma once

#include <AzCore/EBus/EBus.h>

namespace PlayFabClientSdk
{
    class PlayFabClient_SettingsRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        // Read-Only Section
        virtual AZStd::string GetBuildIdentifier() = 0;

        // Read/Write Section
        virtual void SetTitleId(AZStd::string newTitleId) = 0;
        virtual AZStd::string GetTitleId() = 0;

    };

    using PlayFabClient_SettingsRequestBus = AZ::EBus<PlayFabClient_SettingsRequests>;
} // namespace PlayFabClientSdk
