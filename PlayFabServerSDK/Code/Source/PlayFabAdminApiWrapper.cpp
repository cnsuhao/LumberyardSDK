#include "StdAfx.h"
#include "PlayFabAdminApi.h"
#include "PlayFabAdminApiWrapper.h"

using namespace PlayFab;
PlayFabAdminApiWrapper PlayFabAdminApiWrapper::globalWrapper;

// ------------ Generated API call wrappers

void PlayFabAdminApiWrapper::BanUsers(AdminModels::BanUsersRequest& request, ProcessApiCallback<AdminModels::BanUsersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::BanUsers(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserAccountInfo(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserBans(AdminModels::GetUserBansRequest& request, ProcessApiCallback<AdminModels::GetUserBansResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserBans(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ResetUsers(AdminModels::ResetUsersRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ResetUsers(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RevokeAllBansForUser(AdminModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RevokeAllBansForUser(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RevokeBans(AdminModels::RevokeBansRequest& request, ProcessApiCallback<AdminModels::RevokeBansResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RevokeBans(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SendAccountRecoveryEmail(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateBans(AdminModels::UpdateBansRequest& request, ProcessApiCallback<AdminModels::UpdateBansResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateBans(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserTitleDisplayName(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::CreatePlayerStatisticDefinition(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::DeleteUsers(AdminModels::DeleteUsersRequest& request, ProcessApiCallback<AdminModels::DeleteUsersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::DeleteUsers(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetDataReport(AdminModels::GetDataReportRequest& request, ProcessApiCallback<AdminModels::GetDataReportResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetDataReport(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetPlayerStatisticDefinitions(ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetPlayerStatisticDefinitions(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserPublisherData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserPublisherData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserPublisherInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::IncrementPlayerStatisticVersion(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RefundPurchase(AdminModels::RefundPurchaseRequest& request, ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RefundPurchase(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ResetUserStatistics(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request, ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ResolvePurchaseDispute(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdatePlayerStatisticDefinition(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserPublisherInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserPublisherReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateUserReadOnlyData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AddNews(AdminModels::AddNewsRequest& request, ProcessApiCallback<AdminModels::AddNewsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AddNews(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AddVirtualCurrencyTypes(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::DeleteStore(AdminModels::DeleteStoreRequest& request, ProcessApiCallback<AdminModels::DeleteStoreResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::DeleteStore(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetCatalogItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetPublisherData(AdminModels::GetPublisherDataRequest& request, ProcessApiCallback<AdminModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetPublisherData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetRandomResultTables(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetStoreItems(AdminModels::GetStoreItemsRequest& request, ProcessApiCallback<AdminModels::GetStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetStoreItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetTitleData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetTitleData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetTitleInternalData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetTitleInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ListVirtualCurrencyTypes(ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ListVirtualCurrencyTypes(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RemoveVirtualCurrencyTypes(AdminModels::RemoveVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RemoveVirtualCurrencyTypes(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetCatalogItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetStoreItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetTitleData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetTitleData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetTitleInternalData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetTitleInternalData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetupPushNotification(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateCatalogItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateRandomResultTables(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateStoreItems(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetUserInventory(AdminModels::GetUserInventoryRequest& request, ProcessApiCallback<AdminModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetUserInventory(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GrantItemsToUsers(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RevokeInventoryItem(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetMatchmakerGameInfo(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetMatchmakerGameModes(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ModifyMatchmakerGameModes(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AddServerBuild(AdminModels::AddServerBuildRequest& request, ProcessApiCallback<AdminModels::AddServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AddServerBuild(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetServerBuildInfo(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetServerBuildUploadUrl(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ListServerBuilds(ProcessApiCallback<AdminModels::ListBuildsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ListServerBuilds(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ModifyServerBuild(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RemoveServerBuild(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetPublisherData(AdminModels::SetPublisherDataRequest& request, ProcessApiCallback<AdminModels::SetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetPublisherData(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetCloudScriptRevision(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetCloudScriptVersions(ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetCloudScriptVersions(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::SetPublishedRevision(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateCloudScript(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::DeleteContent(AdminModels::DeleteContentRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::DeleteContent(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetContentList(AdminModels::GetContentListRequest& request, ProcessApiCallback<AdminModels::GetContentListResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetContentList(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetContentUploadUrl(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::ResetCharacterStatistics(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AddPlayerTag(AdminModels::AddPlayerTagRequest& request, ProcessApiCallback<AdminModels::AddPlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AddPlayerTag(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetAllActionGroups(ProcessApiCallback<AdminModels::GetAllActionGroupsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetAllActionGroups(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetAllSegments(ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetAllSegments(callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetPlayerSegments(AdminModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetPlayerSegments(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetPlayersInSegment(AdminModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetPlayersInSegment(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetPlayerTags(AdminModels::GetPlayerTagsRequest& request, ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetPlayerTags(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RemovePlayerTag(AdminModels::RemovePlayerTagRequest& request, ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RemovePlayerTag(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::AbortTaskInstance(AdminModels::AbortTaskInstanceRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::AbortTaskInstance(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::CreateActionsOnPlayersInSegmentTask(AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::CreateActionsOnPlayersInSegmentTask(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::CreateCloudScriptTask(AdminModels::CreateCloudScriptTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::CreateCloudScriptTask(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::DeleteTask(AdminModels::DeleteTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::DeleteTask(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetActionsOnPlayersInSegmentTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetActionsOnPlayersInSegmentTaskInstance(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetCloudScriptTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetCloudScriptTaskInstance(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetTaskInstances(AdminModels::GetTaskInstancesRequest& request, ProcessApiCallback<AdminModels::GetTaskInstancesResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetTaskInstances(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::GetTasks(AdminModels::GetTasksRequest& request, ProcessApiCallback<AdminModels::GetTasksResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::GetTasks(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::RunTask(AdminModels::RunTaskRequest& request, ProcessApiCallback<AdminModels::RunTaskResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::RunTask(request, callback, errorCallback, customData);
}

void PlayFabAdminApiWrapper::UpdateTask(AdminModels::UpdateTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
{
    PlayFabAdminApi::UpdateTask(request, callback, errorCallback, customData);
}

