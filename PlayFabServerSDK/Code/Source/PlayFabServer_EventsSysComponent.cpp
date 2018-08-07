
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServer_EventsSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabEventsApi.h"

namespace PlayFabServerSdk
{
    void PlayFabServer_EventsSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServer_EventsSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServer_EventsSysComponent>("PlayFabServer_Events", "Provides access to the Events API within the PlayFab Server SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServer_EventsSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServer_EventsService"));
    }

    void PlayFabServer_EventsSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServer_EventsService"));
    }

    void PlayFabServer_EventsSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServer_EventsSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServer_EventsSysComponent::Init()
    {
    }

    void PlayFabServer_EventsSysComponent::Activate()
    {
        PlayFabServer_EventsRequestBus::Handler::BusConnect();
    }

    void PlayFabServer_EventsSysComponent::Deactivate()
    {
        PlayFabServer_EventsRequestBus::Handler::BusDisconnect();
    }

    int PlayFabServer_EventsSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabServer_EventsSysComponent::WriteEvents(EventsModels::WriteEventsRequest& request, ProcessApiCallback<EventsModels::WriteEventsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEventsApi::WriteEvents(request, callback, errorCallback, customData);
    }
}
