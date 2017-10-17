
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_AdminSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabAdminApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_AdminSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_AdminSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_AdminSysComponent>("PlayFabCombo_Admin", "Provides access to the Admin API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_AdminSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_AdminService"));
    }

    void PlayFabCombo_AdminSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_AdminService"));
    }

    void PlayFabCombo_AdminSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_AdminSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_AdminSysComponent::Init()
    {
    }

    void PlayFabCombo_AdminSysComponent::Activate()
    {
        PlayFabCombo_AdminRequestBus::Handler::BusConnect();
    }

    void PlayFabCombo_AdminSysComponent::Deactivate()
    {
        PlayFabCombo_AdminRequestBus::Handler::BusDisconnect();
    }

    int PlayFabCombo_AdminSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabCombo_AdminSysComponent::AbortTaskInstance(AdminModels::AbortTaskInstanceRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::AbortTaskInstance(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::AddNews(AdminModels::AddNewsRequest& request, ProcessApiCallback<AdminModels::AddNewsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::AddNews(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::AddPlayerTag(AdminModels::AddPlayerTagRequest& request, ProcessApiCallback<AdminModels::AddPlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::AddPlayerTag(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::AddServerBuild(AdminModels::AddServerBuildRequest& request, ProcessApiCallback<AdminModels::AddServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::AddServerBuild(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::AddVirtualCurrencyTypes(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::BanUsers(AdminModels::BanUsersRequest& request, ProcessApiCallback<AdminModels::BanUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::BanUsers(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::CreateActionsOnPlayersInSegmentTask(AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::CreateActionsOnPlayersInSegmentTask(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::CreateCloudScriptTask(AdminModels::CreateCloudScriptTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::CreateCloudScriptTask(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::CreatePlayerSharedSecret(AdminModels::CreatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::CreatePlayerSharedSecret(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::CreatePlayerStatisticDefinition(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::DeleteContent(AdminModels::DeleteContentRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::DeleteContent(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::DeletePlayer(AdminModels::DeletePlayerRequest& request, ProcessApiCallback<AdminModels::DeletePlayerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::DeletePlayer(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::DeletePlayerSharedSecret(AdminModels::DeletePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::DeletePlayerSharedSecret(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::DeleteStore(AdminModels::DeleteStoreRequest& request, ProcessApiCallback<AdminModels::DeleteStoreResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::DeleteStore(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::DeleteTask(AdminModels::DeleteTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::DeleteTask(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetActionsOnPlayersInSegmentTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetActionsOnPlayersInSegmentTaskInstance(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetAllSegments(ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetAllSegments(callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetCatalogItems(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetCloudScriptRevision(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetCloudScriptTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetCloudScriptTaskInstance(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetCloudScriptVersions(ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetCloudScriptVersions(callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetContentList(AdminModels::GetContentListRequest& request, ProcessApiCallback<AdminModels::GetContentListResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetContentList(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetContentUploadUrl(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetDataReport(AdminModels::GetDataReportRequest& request, ProcessApiCallback<AdminModels::GetDataReportResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetDataReport(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetMatchmakerGameInfo(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetMatchmakerGameModes(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetPlayerSegments(AdminModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetPlayerSegments(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetPlayerSharedSecrets(ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetPlayerSharedSecrets(callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetPlayersInSegment(AdminModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetPlayersInSegment(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetPlayerStatisticDefinitions(ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetPlayerStatisticDefinitions(callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetPlayerTags(AdminModels::GetPlayerTagsRequest& request, ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetPlayerTags(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetPolicy(AdminModels::GetPolicyRequest& request, ProcessApiCallback<AdminModels::GetPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetPolicy(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetPublisherData(AdminModels::GetPublisherDataRequest& request, ProcessApiCallback<AdminModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetRandomResultTables(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetServerBuildInfo(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetServerBuildUploadUrl(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetStoreItems(AdminModels::GetStoreItemsRequest& request, ProcessApiCallback<AdminModels::GetStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetStoreItems(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetTaskInstances(AdminModels::GetTaskInstancesRequest& request, ProcessApiCallback<AdminModels::GetTaskInstancesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetTaskInstances(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetTasks(AdminModels::GetTasksRequest& request, ProcessApiCallback<AdminModels::GetTasksResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetTasks(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetTitleData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetTitleData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetTitleInternalData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetTitleInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetUserAccountInfo(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetUserBans(AdminModels::GetUserBansRequest& request, ProcessApiCallback<AdminModels::GetUserBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetUserBans(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetUserData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetUserData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetUserInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetUserInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetUserInventory(AdminModels::GetUserInventoryRequest& request, ProcessApiCallback<AdminModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetUserInventory(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetUserPublisherData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetUserPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetUserPublisherInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::GrantItemsToUsers(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::IncrementPlayerStatisticVersion(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::ListServerBuilds(ProcessApiCallback<AdminModels::ListBuildsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::ListServerBuilds(callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::ListVirtualCurrencyTypes(ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::ListVirtualCurrencyTypes(callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::ModifyMatchmakerGameModes(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::ModifyServerBuild(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::RefundPurchase(AdminModels::RefundPurchaseRequest& request, ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::RefundPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::RemovePlayerTag(AdminModels::RemovePlayerTagRequest& request, ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::RemovePlayerTag(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::RemoveServerBuild(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::RemoveVirtualCurrencyTypes(AdminModels::RemoveVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::RemoveVirtualCurrencyTypes(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::ResetCharacterStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::ResetUserStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request, ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::ResolvePurchaseDispute(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::RevokeAllBansForUser(AdminModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::RevokeAllBansForUser(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::RevokeBans(AdminModels::RevokeBansRequest& request, ProcessApiCallback<AdminModels::RevokeBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::RevokeBans(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::RevokeInventoryItem(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::RunTask(AdminModels::RunTaskRequest& request, ProcessApiCallback<AdminModels::RunTaskResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::RunTask(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SendAccountRecoveryEmail(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SetCatalogItems(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SetPlayerSecret(AdminModels::SetPlayerSecretRequest& request, ProcessApiCallback<AdminModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SetPlayerSecret(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SetPublishedRevision(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SetPublisherData(AdminModels::SetPublisherDataRequest& request, ProcessApiCallback<AdminModels::SetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SetPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SetStoreItems(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SetTitleData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SetTitleData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SetTitleInternalData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SetTitleInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SetupPushNotification(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateBans(AdminModels::UpdateBansRequest& request, ProcessApiCallback<AdminModels::UpdateBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateBans(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateCatalogItems(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateCloudScript(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdatePlayerSharedSecret(AdminModels::UpdatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdatePlayerSharedSecret(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdatePlayerStatisticDefinition(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdatePolicy(AdminModels::UpdatePolicyRequest& request, ProcessApiCallback<AdminModels::UpdatePolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdatePolicy(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateRandomResultTables(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateStoreItems(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateTask(AdminModels::UpdateTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateTask(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateUserData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateUserData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateUserInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateUserPublisherInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateUserReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_AdminSysComponent::UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabAdminApi::UpdateUserTitleDisplayName(request, callback, errorCallback, customData);
    }
}
