using Outbreak.Launcher;
using System.Text.Json;
int checks=0;
KeyboardInputTests.Run((passed,message)=>{if(!passed)throw new IOException(message);checks++;});
Console.WriteLine(JsonSerializer.Serialize(new{passed=true,checks}));
