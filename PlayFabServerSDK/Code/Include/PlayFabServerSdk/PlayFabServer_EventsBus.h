
#pragma once

#include <PlayFabServerSdk/PlayFabError.h>
#include <PlayFabServerSdk/PlayFabEventsDataModels.h>
#include <AzCore/EBus/EBus.h>

namespace PlayFabServerSdk
{
    class PlayFabServer_EventsRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual int GetPendingCalls() = 0;

        // ------------ Generated API call wrappers
        virtual void WriteEvents(EventsModels::WriteEventsRequest& request, ProcessApiCallback<EventsModels::WriteEventsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
    };

    using PlayFabServer_EventsRequestBus = AZ::EBus<PlayFabServer_EventsRequests>;
} // namespace PlayFabServerSdk
