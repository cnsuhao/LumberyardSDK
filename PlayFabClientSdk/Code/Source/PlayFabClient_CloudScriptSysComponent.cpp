
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClient_CloudScriptSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabCloudScriptApi.h"

namespace PlayFabClientSdk
{
    void PlayFabClient_CloudScriptSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabClient_CloudScriptSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabClient_CloudScriptSysComponent>("PlayFabClient_CloudScript", "Provides access to the CloudScript API within the PlayFab Client SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabClient_CloudScriptSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabClient_CloudScriptService"));
    }

    void PlayFabClient_CloudScriptSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabClient_CloudScriptService"));
    }

    void PlayFabClient_CloudScriptSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabClient_CloudScriptSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabClient_CloudScriptSysComponent::Init()
    {
    }

    void PlayFabClient_CloudScriptSysComponent::Activate()
    {
        PlayFabClient_CloudScriptRequestBus::Handler::BusConnect();
    }

    void PlayFabClient_CloudScriptSysComponent::Deactivate()
    {
        PlayFabClient_CloudScriptRequestBus::Handler::BusDisconnect();
    }

    int PlayFabClient_CloudScriptSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabClient_CloudScriptSysComponent::ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabCloudScriptApi::ExecuteEntityCloudScript(request, callback, errorCallback, customData);
    }
}
