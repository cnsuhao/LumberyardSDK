
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServer_CloudScriptSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabCloudScriptApi.h"

namespace PlayFabServerSdk
{
    void PlayFabServer_CloudScriptSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServer_CloudScriptSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServer_CloudScriptSysComponent>("PlayFabServer_CloudScript", "Provides access to the CloudScript API within the PlayFab Server SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServer_CloudScriptSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServer_CloudScriptService"));
    }

    void PlayFabServer_CloudScriptSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServer_CloudScriptService"));
    }

    void PlayFabServer_CloudScriptSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServer_CloudScriptSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServer_CloudScriptSysComponent::Init()
    {
    }

    void PlayFabServer_CloudScriptSysComponent::Activate()
    {
        PlayFabServer_CloudScriptRequestBus::Handler::BusConnect();
    }

    void PlayFabServer_CloudScriptSysComponent::Deactivate()
    {
        PlayFabServer_CloudScriptRequestBus::Handler::BusDisconnect();
    }

    int PlayFabServer_CloudScriptSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabServer_CloudScriptSysComponent::ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabCloudScriptApi::ExecuteEntityCloudScript(request, callback, errorCallback, customData);
    }
}
