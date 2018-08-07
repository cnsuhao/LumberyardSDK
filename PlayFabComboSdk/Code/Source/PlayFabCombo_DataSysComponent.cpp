
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_DataSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabDataApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_DataSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_DataSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_DataSysComponent>("PlayFabCombo_Data", "Provides access to the Data API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_DataSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_DataService"));
    }

    void PlayFabCombo_DataSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_DataService"));
    }

    void PlayFabCombo_DataSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_DataSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_DataSysComponent::Init()
    {
    }

    void PlayFabCombo_DataSysComponent::Activate()
    {
        PlayFabCombo_DataRequestBus::Handler::BusConnect();
    }

    void PlayFabCombo_DataSysComponent::Deactivate()
    {
        PlayFabCombo_DataRequestBus::Handler::BusDisconnect();
    }

    int PlayFabCombo_DataSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabCombo_DataSysComponent::AbortFileUploads(DataModels::AbortFileUploadsRequest& request, ProcessApiCallback<DataModels::AbortFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::AbortFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_DataSysComponent::DeleteFiles(DataModels::DeleteFilesRequest& request, ProcessApiCallback<DataModels::DeleteFilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::DeleteFiles(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_DataSysComponent::FinalizeFileUploads(DataModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<DataModels::FinalizeFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::FinalizeFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_DataSysComponent::GetFiles(DataModels::GetFilesRequest& request, ProcessApiCallback<DataModels::GetFilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::GetFiles(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_DataSysComponent::GetObjects(DataModels::GetObjectsRequest& request, ProcessApiCallback<DataModels::GetObjectsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::GetObjects(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_DataSysComponent::InitiateFileUploads(DataModels::InitiateFileUploadsRequest& request, ProcessApiCallback<DataModels::InitiateFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::InitiateFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_DataSysComponent::SetObjects(DataModels::SetObjectsRequest& request, ProcessApiCallback<DataModels::SetObjectsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::SetObjects(request, callback, errorCallback, customData);
    }
}
