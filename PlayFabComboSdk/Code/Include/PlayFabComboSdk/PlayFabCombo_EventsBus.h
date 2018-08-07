
#pragma once

#include <PlayFabComboSdk/PlayFabError.h>
#include <PlayFabComboSdk/PlayFabEventsDataModels.h>
#include <AzCore/EBus/EBus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_EventsRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual int GetPendingCalls() = 0;

        // ------------ Generated API call wrappers
        virtual void WriteEvents(EventsModels::WriteEventsRequest& request, ProcessApiCallback<EventsModels::WriteEventsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
    };

    using PlayFabCombo_EventsRequestBus = AZ::EBus<PlayFabCombo_EventsRequests>;
} // namespace PlayFabComboSdk
