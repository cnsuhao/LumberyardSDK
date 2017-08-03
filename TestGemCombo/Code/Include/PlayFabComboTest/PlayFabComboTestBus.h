
#pragma once

#include <AzCore/EBus/EBus.h>

namespace PlayFabComboTest
{
    class PlayFabComboTestRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        // Public functions
    };
    using PlayFabComboTestRequestBus = AZ::EBus<PlayFabComboTestRequests>;
} // namespace PlayFabComboTest
