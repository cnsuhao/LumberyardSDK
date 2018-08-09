
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClient_AuthenticationSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabAuthenticationApi.h"

namespace PlayFabClientSdk
{
    void PlayFabClient_AuthenticationSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabClient_AuthenticationSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabClient_AuthenticationSysComponent>("PlayFabClient_Authentication", "Provides access to the Authentication API within the PlayFab Client SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabClient_AuthenticationSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabClient_AuthenticationService"));
    }

    void PlayFabClient_AuthenticationSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabClient_AuthenticationService"));
    }

    void PlayFabClient_AuthenticationSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabClient_AuthenticationSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabClient_AuthenticationSysComponent::Init()
    {
    }

    void PlayFabClient_AuthenticationSysComponent::Activate()
    {
        PlayFabClient_AuthenticationRequestBus::Handler::BusConnect();
    }

    void PlayFabClient_AuthenticationSysComponent::Deactivate()
    {
        PlayFabClient_AuthenticationRequestBus::Handler::BusDisconnect();
    }

    int PlayFabClient_AuthenticationSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabClient_AuthenticationSysComponent::GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAuthenticationApi::GetEntityToken(request, callback, errorCallback, customData);
    }
}
