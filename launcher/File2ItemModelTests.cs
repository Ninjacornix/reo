using System.IO;

namespace Outbreak.Launcher;

internal static class File2ItemModelTests {
    static byte[] Chunk(uint type, uint count, params byte[][] children) {
        using var stream=new MemoryStream();using var output=new BinaryWriter(stream);
        output.Write(type);output.Write(count);output.Write(0);
        foreach(var child in children) output.Write(child);
        stream.Position=8;output.Write((uint)stream.Length);return stream.ToArray();
    }
    static byte[] Models(params ushort[] types) {
        var roots=new byte[types.Length*4];var nodes=new List<byte[]>();
        for(int i=0;i<types.Length;++i) {
            BitConverter.TryWriteBytes(roots.AsSpan(i*4,4),(uint)i);
            var node=new byte[268];
            void Put(int at,uint value)=>BitConverter.TryWriteBytes(node.AsSpan(at,4),value);
            Put(0,0x40000001);Put(4,1);Put(8,268);Put(12,(uint)i);
            foreach(int at in new[]{16,20,24,76}) Put(at,uint.MaxValue);
            Put(80,types[i]);nodes.Add(node);
        }
        var amo=Chunk(1,4,Chunk(0x20000,0),Chunk(2,(uint)types.Length,
            types.Select(_=>Chunk(1,0)).ToArray()),Chunk(9,0),Chunk(10,0));
        var ahi=Chunk(0xc0000000,(uint)types.Length+1,
            new[]{Chunk(0,(uint)types.Length,roots)}.Concat(nodes).ToArray());
        using var stream=new MemoryStream();using var output=new BinaryWriter(stream);
        output.Write(new byte[64]);
        foreach(var (kind,bytes,header) in new[]{("TEX\0",Array.Empty<byte>(),0),("AMO\0",amo,16),("AHI\0",ahi,32)}) {
            long offset=stream.Position;output.Write(bytes);long end=stream.Position;stream.Position=header;
            output.Write(System.Text.Encoding.ASCII.GetBytes(kind));output.Write((uint)offset);output.Write(bytes.Length);output.Write(0);
            stream.Position=end;
        }
        return stream.ToArray();
    }
    static byte[] Materials(params (ushort Type,byte Root,byte[] Aux)[] entries) {
        using var stream=new MemoryStream();using var output=new BinaryWriter(stream);
        output.Write(entries.Length);output.Write(new byte[12+entries.Length*8]);
        for(int i=0;i<entries.Length;++i) {
            var entry=entries[i];long offset=stream.Position;output.Write(entry.Aux);long end=stream.Position;
            stream.Position=16+i*8;output.Write(entry.Type);output.Write(entry.Root);
            output.Write((byte)(entry.Aux.Length/32));output.Write(entry.Aux.Length==0 ? 0u : (uint)offset);stream.Position=end;
        }
        return stream.ToArray();
    }
    internal static void Run(Action<bool,string> check) {
        byte[] aux=Enumerable.Repeat((byte)0x5a,64).ToArray();
        var sources=new Dictionary<int,byte[]> { [20]=Models(0,200,250,300), [6]=Models(20,200,250,300) };
        var materialSources=new Dictionary<int,byte[]> {
            [20]=Materials((0,0,Array.Empty<byte>()),(200,1,Array.Empty<byte>()),(250,2,Array.Empty<byte>()),(300,3,Array.Empty<byte>()),(301,3,aux)),
            [6]=Materials((20,0,Array.Empty<byte>()),(200,1,Array.Empty<byte>()),(250,2,Array.Empty<byte>()),(300,3,Array.Empty<byte>()))
        };
        var banks=new GlobalItemModels.PreparedBanks(sources,materialSources);
        var allowed=new HashSet<ushort> {0,20,200,250,300,301};
        check(banks.RootCount(20,allowed)==5 && banks.MaterialCount(20,allowed)==6,
            "File #2 native material aliases share a model root instead of consuming a duplicate root");
        byte[] merged=banks.Build(20,allowed), materials=banks.BuildMaterials(20,allowed,merged);
        check(BitConverter.ToInt32(materials)==6 && materials.AsSpan(16,4).SequenceEqual(materialSources[20].AsSpan(16,4)),
            "Merged File #2 materials preserve original type/root bindings before appending donors");
        int offset=(int)BitConverter.ToUInt32(materials,16+4*8+4);
        check(materials.AsSpan(offset,64).SequenceEqual(aux) && materials[16+4*8+2]==3,
            "File #2 shared-model alias retains its authored auxiliary transforms and root ordinal");
        byte[] floor=banks.Availability(materials);
        check(floor.Length==608 && floor.AsSpan(0,8).SequenceEqual("RGIF1\0\0\0"u8) &&
              floor[8+20]==1 && floor[8+301]==1 && floor[8+315]==0 && floor[8+317]==0,
              "Floor eligibility includes exact material aliases and excludes items without a model binding");
        byte[] invalid=(byte[])materialSources[20].Clone();invalid[19]=5;
        try {
            _=new GlobalItemModels.PreparedBanks(sources,new() { [20]=invalid,[6]=materialSources[6] });
            check(false,"Oversize material auxiliary table rejected");
        } catch(IOException) {check(true,"Oversize material auxiliary table rejected");}
    }
}
