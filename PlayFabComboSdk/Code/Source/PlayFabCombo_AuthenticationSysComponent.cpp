
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_AuthenticationSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabAuthenticationApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_AuthenticationSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_AuthenticationSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_AuthenticationSysComponent>("PlayFabCombo_Authentication", "Provides access to the Authentication API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_AuthenticationSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_AuthenticationService"));
    }

    void PlayFabCombo_AuthenticationSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_AuthenticationService"));
    }

    void PlayFabCombo_AuthenticationSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_AuthenticationSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_AuthenticationSysComponent::Init()
    {
    }

    void PlayFabCombo_AuthenticationSysComponent::Activate()
    {
        PlayFabCombo_AuthenticationRequestBus::Handler::BusConnect();
    }

    void PlayFabCombo_AuthenticationSysComponent::Deactivate()
    {
        PlayFabCombo_AuthenticationRequestBus::Handler::BusDisconnect();
    }

    int PlayFabCombo_AuthenticationSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabCombo_AuthenticationSysComponent::GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAuthenticationApi::GetEntityToken(request, callback, errorCallback, customData);
    }
}
