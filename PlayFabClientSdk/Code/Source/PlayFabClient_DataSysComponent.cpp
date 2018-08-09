
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClient_DataSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabDataApi.h"

namespace PlayFabClientSdk
{
    void PlayFabClient_DataSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabClient_DataSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabClient_DataSysComponent>("PlayFabClient_Data", "Provides access to the Data API within the PlayFab Client SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabClient_DataSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabClient_DataService"));
    }

    void PlayFabClient_DataSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabClient_DataService"));
    }

    void PlayFabClient_DataSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabClient_DataSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabClient_DataSysComponent::Init()
    {
    }

    void PlayFabClient_DataSysComponent::Activate()
    {
        PlayFabClient_DataRequestBus::Handler::BusConnect();
    }

    void PlayFabClient_DataSysComponent::Deactivate()
    {
        PlayFabClient_DataRequestBus::Handler::BusDisconnect();
    }

    int PlayFabClient_DataSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabClient_DataSysComponent::AbortFileUploads(DataModels::AbortFileUploadsRequest& request, ProcessApiCallback<DataModels::AbortFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::AbortFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabClient_DataSysComponent::DeleteFiles(DataModels::DeleteFilesRequest& request, ProcessApiCallback<DataModels::DeleteFilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::DeleteFiles(request, callback, errorCallback, customData);
    }
    void PlayFabClient_DataSysComponent::FinalizeFileUploads(DataModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<DataModels::FinalizeFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::FinalizeFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabClient_DataSysComponent::GetFiles(DataModels::GetFilesRequest& request, ProcessApiCallback<DataModels::GetFilesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::GetFiles(request, callback, errorCallback, customData);
    }
    void PlayFabClient_DataSysComponent::GetObjects(DataModels::GetObjectsRequest& request, ProcessApiCallback<DataModels::GetObjectsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::GetObjects(request, callback, errorCallback, customData);
    }
    void PlayFabClient_DataSysComponent::InitiateFileUploads(DataModels::InitiateFileUploadsRequest& request, ProcessApiCallback<DataModels::InitiateFileUploadsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::InitiateFileUploads(request, callback, errorCallback, customData);
    }
    void PlayFabClient_DataSysComponent::SetObjects(DataModels::SetObjectsRequest& request, ProcessApiCallback<DataModels::SetObjectsResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabDataApi::SetObjects(request, callback, errorCallback, customData);
    }
}
