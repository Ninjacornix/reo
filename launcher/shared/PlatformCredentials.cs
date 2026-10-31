using System.Diagnostics;
using System.Security.Cryptography;
using System.Text;

namespace Outbreak.Launcher;

internal static class PlatformCredentials {
    internal static string Get(string host,string username) {
        if(OperatingSystem.IsMacOS()) {
            string root=PlatformPaths.FindRoot(AppContext.BaseDirectory);
            string helper=new[]{Path.Combine(AppContext.BaseDirectory,"tools","AccountKeychain"),Path.Combine(root,"build-macos","launcher-tools","AccountKeychain")}.FirstOrDefault(File.Exists)
                ?? throw new IOException("The macOS Keychain helper is missing from this installation.");
            return Run(helper,[host,username]);
        }
        string identity=Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(host+"\n"+username)));
        string value=Run("secret-tool",["lookup","application","OutbreakRecomp","identity",identity],allowEmpty:true,allowMissing:true);
        if(value.Length>0)return value;
        const string alphabet="abcdefghijklmnopqrstuvwxyz0123456789";
        value=new string(Enumerable.Range(0,15).Select(_=>alphabet[RandomNumberGenerator.GetInt32(alphabet.Length)]).ToArray());
        Run("secret-tool",["store","--label=Outbreak network account","application","OutbreakRecomp","identity",identity],value,true);
        return value;
    }
    static string Run(string executable,string[] args,string? input=null,bool allowEmpty=false,bool allowMissing=false) {
        var start=new ProcessStartInfo(executable){UseShellExecute=false,RedirectStandardOutput=true,RedirectStandardError=true,RedirectStandardInput=input!=null};
        foreach(var arg in args)start.ArgumentList.Add(arg);
        using var process=Process.Start(start)??throw new IOException("Could not open the operating system credential store.");
        if(input!=null){process.StandardInput.Write(input);process.StandardInput.Close();}
        var output=process.StandardOutput.ReadToEndAsync();var error=process.StandardError.ReadToEndAsync();
        if(!process.WaitForExit(60000)){process.Kill(true);throw new IOException("Credential-store access timed out.");}
        string value=output.GetAwaiter().GetResult().Trim();error.GetAwaiter().GetResult();
        if(value.Length==0&&((allowEmpty&&process.ExitCode==0)||(allowMissing&&process.ExitCode==1)))return "";
        if(process.ExitCode!=0||value.Length!=15||value.Any(c=>!char.IsAsciiLetterOrDigit(c)))
            throw new IOException(OperatingSystem.IsMacOS()?"Could not access the saved network credential in macOS Keychain.":"Could not access the saved network credential. Linux requires a running Secret Service and secret-tool.");
        return value;
    }
}
