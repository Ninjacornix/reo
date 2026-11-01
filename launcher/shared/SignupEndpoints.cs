namespace Outbreak.Launcher;

// RC1 MainWindow.SignupEndpoint, shared by the common launcher and GameSession.
// Hosts sign up with their own server on this PC: many routers cannot reach their own public
// address from inside. Joiners use the port their host announced, if any.
internal static class SignupEndpoints {
    internal static Uri? For(Settings settings, string? hostedAddress) {
        OnlineOptions.TryHost(settings.CoopHost, out string host);
        if (settings.ResolvedCoopMode == "host" && (hostedAddress == null || hostedAddress == host))
            return AutomaticAccount.SignupEndpoint("127.0.0.1", settings.SignupPort);
        return settings.ResolvedCoopMode == "join" && settings.JoinSignupPort > 0
                   ? AutomaticAccount.SignupEndpoint(host, settings.JoinSignupPort)
                   : null;
    }
}
