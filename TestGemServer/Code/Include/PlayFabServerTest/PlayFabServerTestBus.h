
#pragma once

#include <AzCore/EBus/EBus.h>

namespace PlayFabServerTest
{
    class PlayFabServerTestRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        // Public functions
    };
    using PlayFabServerTestRequestBus = AZ::EBus<PlayFabServerTestRequests>;
} // namespace PlayFabServerTest
