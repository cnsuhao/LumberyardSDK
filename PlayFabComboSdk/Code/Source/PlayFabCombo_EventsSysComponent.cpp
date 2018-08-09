
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_EventsSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabEventsApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_EventsSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_EventsSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_EventsSysComponent>("PlayFabCombo_Events", "Provides access to the Events API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_EventsSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_EventsService"));
    }

    void PlayFabCombo_EventsSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_EventsService"));
    }

    void PlayFabCombo_EventsSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_EventsSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_EventsSysComponent::Init()
    {
    }

    void PlayFabCombo_EventsSysComponent::Activate()
    {
        PlayFabCombo_EventsRequestBus::Handler::BusConnect();
    }

    void PlayFabCombo_EventsSysComponent::Deactivate()
    {
        PlayFabCombo_EventsRequestBus::Handler::BusDisconnect();
    }

    int PlayFabCombo_EventsSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabCombo_EventsSysComponent::WriteEvents(EventsModels::WriteEventsRequest& request, ProcessApiCallback<EventsModels::WriteEventsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabEventsApi::WriteEvents(request, callback, errorCallback, customData);
    }
}
