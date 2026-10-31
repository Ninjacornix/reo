using System.Runtime.InteropServices;
using System.Text.Json;

namespace Outbreak.Launcher;

public static class PlatformPaths {
    public static string Platform => OperatingSystem.IsWindows() ? "win" : OperatingSystem.IsMacOS() ? "osx" : "linux";
    public static string RuntimeId => Platform + "-" + RuntimeInformation.ProcessArchitecture.ToString().ToLowerInvariant();
    public static string DataHome(string root) {
        if (OperatingSystem.IsWindows()) return Path.Combine(root,"data");
        string home=Environment.GetFolderPath(Environment.SpecialFolder.UserProfile);
        if (OperatingSystem.IsMacOS()) return Path.Combine(home,"Library","Application Support","OutbreakRecomp");
        string data=Environment.GetEnvironmentVariable("XDG_DATA_HOME") ?? Path.Combine(home,".local","share");
        return Path.Combine(data,"OutbreakRecomp");
    }
    public static string FindRoot(string start) {
        for (var folder=new DirectoryInfo(start);folder!=null;folder=folder.Parent)
            if (File.Exists(Path.Combine(folder.FullName,"native-build.json")) || File.Exists(Path.Combine(folder.FullName,"CMakeLists.txt")) || File.Exists(Path.Combine(folder.FullName,"distribution.json")))
                return folder.FullName;
        return start;
    }
    public static Dictionary<string,string>? NativeRecord(string root) {
        foreach (string path in new[]{Path.Combine(AppContext.BaseDirectory,"native-build.json"),Path.Combine(root,OperatingSystem.IsMacOS()?"build-macos":"build-"+Platform,OperatingSystem.IsMacOS()?"macos-build.json":"native-build.json")}) {
            if (!File.Exists(path))continue;
            using var doc=JsonDocument.Parse(File.ReadAllText(path));
            var result=doc.RootElement.EnumerateObject().Where(p=>p.Value.ValueKind==JsonValueKind.String)
                .ToDictionary(p=>p.Name,p=>p.Value.GetString()!);
            foreach(string key in new[]{"executable","driver","data","iso"})
                if(result.TryGetValue(key,out var value)&&!Path.IsPathRooted(value))result[key]=Path.GetFullPath(Path.Combine(Path.GetDirectoryName(path)!,value));
            return result;
        }
        return null;
    }
    public static string GameExecutable(string root,string game) {
        if(game=="file1" && NativeRecord(root) is {} record)return record["executable"];
        string name=game=="file2"?"reo_recomp_file2":"reo_recomp";
        return Path.Combine(root,OperatingSystem.IsWindows()?"build-ninja":"build-"+Platform,"recomp",name+(OperatingSystem.IsWindows()?".exe":""));
    }
}
