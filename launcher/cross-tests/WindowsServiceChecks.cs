using Outbreak.Launcher;

internal static class WindowsServiceChecks {
    internal static async Task Run(Action<bool,string> check) {
        if (!OperatingSystem.IsWindows()) throw new PlatformNotSupportedException("Windows service/adapter checks.");
        AssetExportTests.Run(check);
        AudioMixerTests.Run(check);
        AudioOutputTests.Run(check);
        await AutomaticAccountTests.Run(check);
        BuildPathLinksTests.Run(check);
        BundledRandomizerTests.Run(check);
        CheatCompatibilityTests.Run(check);
        ControllerDiscoveryTests.Run(check);
        ControllerInputTests.Run(check);
        ControllerLightTests.Run(check);
        ControllerRumbleTests.Run(check);
        CoopAutomationTests.Run(check);
        CoopSmokeOptionsTests.Run(check);
        await ExistingGameBuildTests.Run(check);
        await File2LauncherTests.Run(check);
        File2LobbyTests.Run(check);
        GameImageCacheTests.Run(check);
        LocalBuildPayloadTests.Run(check);
        await LocalGameBuildTests.Run(check);
        ProgressionUnlockTests.Run(check);
        ReferencePakModTests.Run(check);
        StaleImportTests.Run(check);
        StorageTests.Run(check);
        SubtitleControlTests.Run(check);
        NetworkTraceTests.Run(check);
        DeveloperOptionsTests.Run(check);
    }
}
