using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class RandomizerSessionTests {
    internal static async Task Run(Action<bool,string> check) {
        var sample=Mods.Parse(File.ReadAllText(Path.Combine(AppContext.BaseDirectory,"examples","mods","randomizer.json")));
        sample.EnemyRandomizer!.Seed=2032; // Varied species fixture, using the normal seed input.
        byte[] config=RandomizerSession.Create("reo01",new() {sample});
        var parsed=RandomizerSession.Parse(config);
        check(parsed.Items?.Seed==sample.ItemRandomizer?.Seed && parsed.Enemies?.Seed==sample.EnemyRandomizer?.Seed,
            "Host publishes both randomizer seeds");
        check(parsed.Items?.Mode=="global" && parsed.Enemies!.Pool.Count>32,
            "Host preserves global item mode and the expanded enemy roster");
        var adopted=RandomizerSession.ModsFor(parsed).Single();
        check(adopted.EnemyRandomizer!.Pool.Count==sample.EnemyRandomizer!.Pool.Count && adopted.Effects.Count==0 && adopted.Patches.Count==0,
            "Host session adopts complete pool without executable mods or cheats");
        sample.EnemyRandomizer.Seed++;
        check(RandomizerSession.Parse(config).Enemies!.Seed!=sample.EnemyRandomizer.Seed,"Published session is immutable");
        byte[] empty=RandomizerSession.Create("reo01",new());
        check(RandomizerSession.ModsFor(RandomizerSession.Parse(empty)).Count==0,"Unmodded host clears guest randomizers");
        void Reject(Action action,string label) { try { action(); check(false,label); } catch(IOException) {check(true,label);} }
        Reject(()=>RandomizerSession.Parse(Encoding.UTF8.GetBytes(Encoding.UTF8.GetString(config).Replace("\"protocol\":3","\"protocol\":999"))),"Incompatible protocol rejected");
        Reject(()=>RandomizerSession.Parse(Encoding.UTF8.GetBytes(Encoding.UTF8.GetString(config).Replace("\"protocol\":3,",""))),"Missing protocol rejected");
        Reject(()=>RandomizerSession.Parse(Encoding.UTF8.GetBytes(Encoding.UTF8.GetString(config).Replace("\"protocol\":3","\"protocol\":2"))),"Old independently rolled enemy sessions rejected");
        var invalidWeight=System.Text.Json.Nodes.JsonNode.Parse(config)!;
        invalidWeight["enemies"]!["pool"]![0]!["weight"]=0;
        Reject(()=>RandomizerSession.Parse(Encoding.UTF8.GetBytes(invalidWeight.ToJsonString())),"Invalid network profile rejected");
        Reject(()=>RandomizerSession.Parse(new byte[RandomizerSession.MaxPacket]),"Oversize session rejected");
        sample.Effects.Add("health");
        Reject(()=>RandomizerSession.Create("HostTest",new() {sample}),"Effects cannot be shared as randomizers");
        byte[] nonce=Enumerable.Range(0,16).Select(i=>(byte)i).ToArray();
        byte[] query=RandomizerSession.QueryPrefix.Concat(nonce).ToArray();
        var response=RandomizerSession.Reply(query,config)!;
        check(RandomizerSession.Decode(response,nonce).SequenceEqual(config),"Nonce-bound response preserves exact settings");
        Reject(()=>RandomizerSession.Decode(response,new byte[16]),"Stale nonce rejected");
        Reject(()=>RandomizerSession.Decode(RandomizerSession.Reply(query,null)!,nonce),"Unlaunched host rejected");
        check(RandomizerSession.Reply(new byte[100],config)==null,"Unknown queries ignored");
        using var server=new UdpClient(new IPEndPoint(IPAddress.Loopback,0));
        int port=((IPEndPoint)server.Client.LocalEndPoint!).Port;
        using var timeout=new CancellationTokenSource(TimeSpan.FromSeconds(5));
        var serve=Task.Run(async ()=> {
            var request=await server.ReceiveAsync(timeout.Token);
            var reply=RandomizerSession.Reply(request.Buffer,config)!;
            await server.SendAsync(reply,request.RemoteEndPoint,timeout.Token);
        });
        var fetched=await RandomizerSession.Fetch("127.0.0.1",timeout.Token,port);
        await serve;
        check(fetched.SequenceEqual(config),"Real UDP host-to-guest configuration transfer");
        check(RandomizerSession.Digest(fetched)==RandomizerSession.Digest(config),"Host and guest configuration hashes match");
        using var resolveTimeout=new CancellationTokenSource(TimeSpan.FromSeconds(15));
        var secondSample=Mods.Parse(File.ReadAllText(Path.Combine(AppContext.BaseDirectory,"examples","mods","randomizer-file2.json")));
        secondSample.ItemRandomizer!.Seed=41; secondSample.EnemyRandomizer!.Seed=41;
        byte[] secondConfig=RandomizerSession.Create("reo01",new() {secondSample},"file2");
        var resolveServer=Task.Run(async ()=> {
            foreach(var body in new[] {config,empty,config,secondConfig,config,secondConfig}) {
                var request=await server.ReceiveAsync(resolveTimeout.Token);
                await server.SendAsync(RandomizerSession.Reply(request.Buffer,body)!,request.RemoteEndPoint,resolveTimeout.Token);
            }
        });
        var guest=new Settings { CoopMode="join", CoopHost="127.0.0.1", JoinHostName="reo01", CheatsEnabled=false };
        var resolved=await RandomizerSession.Resolve(guest,new() {sample},resolveTimeout.Token,port);
        check(resolved.Mods.Single().EnemyRandomizer!.Seed==parsed.Enemies!.Seed &&
              resolved.Mods.Single().EnemyRandomizer!.Seed!=sample.EnemyRandomizer.Seed &&
              resolved.Mods.Single().Effects.Count==0,"Join path replaces conflicting local mods with host settings");
        var cleared=await RandomizerSession.Resolve(guest,new() {sample},resolveTimeout.Token,port);
        check(cleared.Mods.Count==0 && sample.Effects.Count==1,"Unmodded host clears session without changing installed package");
        guest.JoinHostName="DifferentHost";
        try { await RandomizerSession.Resolve(guest,new(),resolveTimeout.Token,port); check(false,"Wrong host rejected"); }
        catch(IOException) { check(true,"Wrong host rejected"); }
        guest.SelectedGame="file2"; guest.JoinHostName="reo01";
        var secondResolved=await RandomizerSession.Resolve(guest,new() {sample},resolveTimeout.Token,port);
        check(secondResolved.Bytes.SequenceEqual(secondConfig) && secondResolved.Mods.Single().ElfSha256==DiscImport.SecondElfSha256 &&
              secondResolved.Mods.Single().ItemRandomizer!.Seed==41 &&
              secondResolved.Mods.Single().EnemyRandomizer!.Pool.Count==secondSample.EnemyRandomizer.Pool.Count,
              "Real UDP File #2 join adopts host seeds and complete pool, ignoring File #1 local settings");
        try { await RandomizerSession.Resolve(guest,new(),resolveTimeout.Token,port); check(false,"File #2 UDP join rejects File #1 host"); }
        catch(IOException) { check(true,"File #2 UDP join rejects File #1 host"); }
        guest.SelectedGame="file1";
        try { await RandomizerSession.Resolve(guest,new(),resolveTimeout.Token,port); check(false,"File #1 UDP join rejects File #2 host"); }
        catch(IOException) { check(true,"File #1 UDP join rejects File #2 host"); }
        await resolveServer;
        string receipts=Path.Combine(AppContext.BaseDirectory,"test-results");
        Directory.CreateDirectory(receipts);
        await File.WriteAllTextAsync(Path.Combine(receipts,"randomizer-session-transfer.json"),JsonSerializer.Serialize(new {
            host=parsed, guestMod=resolved.Mods.Single(),
            hostDigest=RandomizerSession.Digest(config), guestDigest=RandomizerSession.Digest(resolved.Bytes),
            note="Actual UDP transfer and production join resolution; native gameplay requires a separate run."
        },new JsonSerializerOptions {PropertyNamingPolicy=JsonNamingPolicy.CamelCase,WriteIndented=true}));
    }
}
