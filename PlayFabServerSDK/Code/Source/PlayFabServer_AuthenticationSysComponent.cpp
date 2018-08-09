
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServer_AuthenticationSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabAuthenticationApi.h"

namespace PlayFabServerSdk
{
    void PlayFabServer_AuthenticationSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServer_AuthenticationSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServer_AuthenticationSysComponent>("PlayFabServer_Authentication", "Provides access to the Authentication API within the PlayFab Server SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServer_AuthenticationSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServer_AuthenticationService"));
    }

    void PlayFabServer_AuthenticationSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServer_AuthenticationService"));
    }

    void PlayFabServer_AuthenticationSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServer_AuthenticationSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServer_AuthenticationSysComponent::Init()
    {
    }

    void PlayFabServer_AuthenticationSysComponent::Activate()
    {
        PlayFabServer_AuthenticationRequestBus::Handler::BusConnect();
    }

    void PlayFabServer_AuthenticationSysComponent::Deactivate()
    {
        PlayFabServer_AuthenticationRequestBus::Handler::BusDisconnect();
    }

    int PlayFabServer_AuthenticationSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabServer_AuthenticationSysComponent::GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAuthenticationApi::GetEntityToken(request, callback, errorCallback, customData);
    }
}
