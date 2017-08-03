del /Q T:\depot\sdks\LumberyardSDK\PlayFabClientSdk
del /Q T:\depot\sdks\LumberyardSDK\PlayFabServerSdk
del /Q T:\depot\sdks\LumberyardSDK\PlayFabComboSdk
del /Q T:\depot\sdks\LumberyardSDK\TestGemClient
del /Q T:\depot\sdks\LumberyardSDK\TestGemServer
del /Q T:\depot\sdks\LumberyardSDK\TestGemCombo

mklink /D T:\dev\Lumberyard\1.9.0.1\dev\Gems\PlayFabClientSdk T:\depot\sdks\LumberyardSDK\PlayFabClientSdk
mklink /D T:\dev\Lumberyard\1.9.0.1\dev\Gems\PlayFabServerSdk T:\depot\sdks\LumberyardSDK\PlayFabServerSdk
mklink /D T:\dev\Lumberyard\1.9.0.1\dev\Gems\PlayFabComboSdk T:\depot\sdks\LumberyardSDK\PlayFabComboSdk
mklink /D T:\dev\Lumberyard\1.9.0.1\dev\Gems\PlayFabClientTest T:\depot\sdks\LumberyardSDK\TestGemClient
mklink /D T:\dev\Lumberyard\1.9.0.1\dev\Gems\PlayFabServerTest T:\depot\sdks\LumberyardSDK\TestGemServer
mklink /D T:\dev\Lumberyard\1.9.0.1\dev\Gems\PlayFabComboTest T:\depot\sdks\LumberyardSDK\TestGemCombo

pause