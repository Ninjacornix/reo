using System.Net;
using System.Net.Sockets;
using Outbreak.Launcher;

internal static class HostingReadinessTests {
    internal static async Task Run(Action<bool, string> check) {
        foreach (string advertised in new[] { "192.0.2.1", "192.168.1.20", "127.0.0.1", "127.8.9.10" }) {
            var bind = IPAddress.IsLoopback(IPAddress.Parse(advertised)) ? IPAddress.Parse(advertised) : IPAddress.Loopback;
            using var signup = new TcpListener(bind, 0);
            using var app = new TcpListener(bind, 0);
            signup.Start(); app.Start();
            using var bootstrap = new UdpClient(AddressFamily.InterNetwork) { ExclusiveAddressUse = true };
            using var game = new UdpClient(AddressFamily.InterNetwork) { ExclusiveAddressUse = true };
            var udpBind = IPAddress.IsLoopback(IPAddress.Parse(advertised)) ? bind : IPAddress.Any;
            bootstrap.Client.Bind(new IPEndPoint(udpBind, 0));
            game.Client.Bind(new IPEndPoint(udpBind, 0));
            int signupPort = ((IPEndPoint)signup.LocalEndpoint).Port, appPort = ((IPEndPoint)app.LocalEndpoint).Port;
            int bootstrapPort = ((IPEndPoint)bootstrap.Client.LocalEndPoint!).Port, gamePort = ((IPEndPoint)game.Client.LocalEndPoint!).Port;
            using var timeout = new CancellationTokenSource(TimeSpan.FromSeconds(5));
            check(await HostedServer.ServicesReady(advertised, signupPort, appPort, bootstrapPort, gamePort, timeout.Token),
                $"Local hosting becomes ready when advertising {advertised}, without requiring NAT loopback");
            app.Stop();
            check(!await HostedServer.ServicesReady(advertised, signupPort, appPort, bootstrapPort, gamePort, timeout.Token),
                "Hosting cannot become ready with its APP service missing");
            app.Start();
            appPort = ((IPEndPoint)app.LocalEndpoint).Port;
            game.Close();
            check(!await HostedServer.ServicesReady(advertised, signupPort, appPort, bootstrapPort, gamePort, timeout.Token),
                "Hosting cannot become ready with its game service missing");
        }
    }
}
