
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_CloudScriptSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabCloudScriptApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_CloudScriptSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_CloudScriptSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_CloudScriptSysComponent>("PlayFabCombo_CloudScript", "Provides access to the CloudScript API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_CloudScriptSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_CloudScriptService"));
    }

    void PlayFabCombo_CloudScriptSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_CloudScriptService"));
    }

    void PlayFabCombo_CloudScriptSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_CloudScriptSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_CloudScriptSysComponent::Init()
    {
    }

    void PlayFabCombo_CloudScriptSysComponent::Activate()
    {
        PlayFabCombo_CloudScriptRequestBus::Handler::BusConnect();
    }

    void PlayFabCombo_CloudScriptSysComponent::Deactivate()
    {
        PlayFabCombo_CloudScriptRequestBus::Handler::BusDisconnect();
    }

    int PlayFabCombo_CloudScriptSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabCombo_CloudScriptSysComponent::ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabCloudScriptApi::ExecuteEntityCloudScript(request, callback, errorCallback, customData);
    }
}
