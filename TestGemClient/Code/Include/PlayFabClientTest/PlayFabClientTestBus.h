
#pragma once

#include <AzCore/EBus/EBus.h>

namespace PlayFabClientTest
{
    class PlayFabClientTestRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        // Public functions
    };
    using PlayFabClientTestRequestBus = AZ::EBus<PlayFabClientTestRequests>;
} // namespace PlayFabClientTest
