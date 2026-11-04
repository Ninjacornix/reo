using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace Outbreak.Launcher;

// Merge only the player's own ordinary object models. NBD chunk/reference layout
// documented by Fothsid: https://gist.github.com/Fothsid/0d01f5d2f3c6d48de8963f5171a2933b
internal static class GlobalItemModels {
    sealed record Bank(uint RootKind, List<byte[]> Textures, List<byte[]> Amo, List<uint> Roots,
                       Dictionary<uint, byte[]> Nodes, Dictionary<uint, uint> Tags);
    sealed record Plan(Bank Bank, HashSet<uint> Wanted, List<uint> Selected,
                       List<(uint Index, byte[] Mesh)> Meshes);
    internal sealed class PreparedBanks {
        readonly Dictionary<int, Bank> banks;
        readonly Dictionary<int, MatBank> mats;
        static readonly Dictionary<ushort, ushort> AmmoBoxes = new() { [201]=200, [203]=200, [209]=200, [210]=200, [251]=250 };
        sealed record MatEntry(ushort Type, byte Root, byte[] Aux);
        sealed record MatBank(byte[] Header, List<MatEntry> Entries);
        internal PreparedBanks(Dictionary<int, byte[]> sources, Dictionary<int, byte[]> materials) {
            banks = sources.ToDictionary(p => p.Key, p => Parse(p.Value));
            mats = materials.ToDictionary(p => p.Key, p => ParseMat(p.Value, banks[p.Key].Roots.Count));
        }
        IEnumerable<Bank> Ordered(int scenario) => new[] { banks[scenario] }
            .Concat(banks.Where(p => p.Key != scenario).Select(p => p.Value));
        static MatBank ParseMat(byte[] data, int roots) {
            uint count = U(data);
            if (count > 96 || data.Length < 16 + count * 8) throw new IOException("Invalid object material table.");
            var entries = new List<MatEntry>(); var types = new HashSet<ushort>();
            for (int i=0; i<count; ++i) {
                int at=16+i*8; ushort type=BitConverter.ToUInt16(data,at); byte root=data[at+2], subcount=data[at+3];
                if (root>=roots || subcount>4 || !types.Add(type)) throw new IOException("Invalid object material binding.");
                int offset=checked((int)U(data,at+4));
                entries.Add(new(type,root,Slice(data,offset,subcount*32)));
            }
            return new(Slice(data,0,16),entries);
        }
        (Bank Bank, MatEntry Entry)? Find(int scenario, ushort type) {
            foreach(int id in new[]{scenario}.Concat(banks.Keys.Where(k=>k!=scenario))) {
                var entry=mats[id].Entries.FirstOrDefault(e=>e.Type==type);
                if(entry!=null) return (banks[id],entry);
            }
            if(AmmoBoxes.TryGetValue(type,out ushort box)) return Find(scenario,box);
            return null;
        }
        internal HashSet<ushort> Types => mats.Values.SelectMany(m=>m.Entries.Select(e=>e.Type))
            .Concat(AmmoBoxes.Keys).ToHashSet();
        HashSet<ushort> Canonical(int scenario,HashSet<ushort> allowed) => allowed.Select(t=>Find(scenario,t))
            .Where(p=>p!=null).Select(p=>(ushort)p!.Value.Bank.Tags[p.Value.Bank.Roots[p.Value.Entry.Root]]).ToHashSet();
        internal int MaterialCount(int scenario,HashSet<ushort> allowed) => mats[scenario].Entries.Count+
            allowed.Count(t=>!mats[scenario].Entries.Any(e=>e.Type==t) && Find(scenario,t)!=null);
        internal int RootCount(int scenario, HashSet<ushort> allowed) {
            allowed=Canonical(scenario,allowed);
            var seen = new HashSet<uint>(); int count = 0;
            foreach (var bank in Ordered(scenario)) {
                bool first = count == 0;
                var wanted = bank.Roots.Select(r => bank.Tags[r])
                    .Where(t => first || t < 600 && !seen.Contains(t) && allowed.Contains((ushort)t)).ToHashSet();
                count += bank.Roots.Count(r => wanted.Contains(bank.Tags[r])); seen.UnionWith(wanted);
            }
            return count;
        }
        internal byte[] Build(int scenario, HashSet<ushort> allowed) =>
            Merge(Ordered(scenario).ToList(),Canonical(scenario,allowed));
        internal byte[] BuildMaterials(int scenario,HashSet<ushort> allowed,byte[] merged) {
            var model=Parse(merged); var basis=mats[scenario]; var entries=new List<MatEntry>(basis.Entries);
            foreach(ushort type in allowed.Order()) {
                if(entries.Any(e=>e.Type==type)) continue;
                var source=Find(scenario,type); if(source==null) continue;
                uint tag=source.Value.Bank.Tags[source.Value.Bank.Roots[source.Value.Entry.Root]];
                int root=model.Roots.FindIndex(r=>model.Tags[r]==tag);
                if(root<0 || root>=96) throw new IOException("Object material binding has no merged model.");
                entries.Add(new(type,(byte)root,source.Value.Entry.Aux));
            }
            if(entries.Count>96) throw new IOException("Object material table exceeds native capacity.");
            using var stream=new MemoryStream();using var output=new BinaryWriter(stream);
            output.Write(basis.Header);output.Write(new byte[entries.Count*8]);
            for(int i=0;i<entries.Count;++i) {
                var e=entries[i];uint offset=(uint)stream.Position;output.Write(e.Aux);
                long end=stream.Position;stream.Position=16+i*8;
                output.Write(e.Type);output.Write(e.Root);output.Write((byte)(e.Aux.Length/32));output.Write(e.Aux.Length==0 ? 0u : offset);
                stream.Position=end;
            }
            stream.Position=0;output.Write(entries.Count);return stream.ToArray();
        }
        internal byte[] Availability(byte[] materials) {
            var parsed=ParseMat(materials,96);var result=new byte[608];"RGIF1\0\0\0"u8.CopyTo(result);
            foreach(var entry in parsed.Entries) if(entry.Type<600) result[8+entry.Type]=1;
            return result;
        }
    }
    static uint U(byte[] data, int at=0) {
        if(at < 0 || at > data.Length - 4) throw new IOException("Incomplete object model.");
        return BitConverter.ToUInt32(data, at);
    }
    static void Put(byte[] data, int at, uint value) => BitConverter.TryWriteBytes(data.AsSpan(at,4),value);
    static byte[] Slice(byte[] data, int at, int length) {
        if(at < 0 || length < 0 || at > data.Length-length) throw new IOException("Invalid object-model range.");
        return data.AsSpan(at,length).ToArray();
    }
    static List<byte[]> Children(byte[] data) {
        var result=new List<byte[]>();
        for(int at=12; at<data.Length;) {
            int size=checked((int)U(data,at+8));
            if(size<12) throw new IOException("Invalid model chunk.");
            result.Add(Slice(data,at,size)); at=checked(at+size);
        }
        return result;
    }
    static byte[] Chunk(uint type, uint count, IEnumerable<byte[]> entries) {
        using var stream=new MemoryStream(); using var writer=new BinaryWriter(stream);
        writer.Write(type);writer.Write(count);writer.Write(0u);
        foreach(var data in entries) writer.Write(data);
        var result=stream.ToArray();Put(result,8,(uint)result.Length);return result;
    }
    static byte[] Words(IEnumerable<uint> values) {
        using var stream=new MemoryStream();using var writer=new BinaryWriter(stream);
        foreach(uint value in values) writer.Write(value);
        return stream.ToArray();
    }
    static Bank Parse(byte[] data) {
        if(!data.AsSpan(0,4).SequenceEqual("TEX\0"u8)) throw new IOException("Object bank lacks textures.");
        var textures=new List<byte[]>();int at=checked((int)U(data,4));uint count=U(data,12);
        if(count>128) throw new IOException("Too many object textures.");
        for(uint i=0;i<count;++i) {
            int size=checked((int)U(data,at)+4);textures.Add(Slice(data,at,size));at=checked(at+size);
        }
        var amo=Children(Slice(data,checked((int)U(data,20)),checked((int)U(data,24))));
        var ahi=Children(Slice(data,checked((int)U(data,36)),checked((int)U(data,40))));
        uint rootKind = U(ahi[0]);
        if(rootKind is not (0 or 0x80000000) || U(ahi[0],4)>100) throw new IOException("Unsupported object hierarchy.");
        var roots=Enumerable.Range(0,(int)U(ahi[0],4)).Select(i=>U(ahi[0],12+i*4)).ToList();
        var nodes=ahi.Skip(1).ToDictionary(n=>U(n,12));
        var tags=nodes.ToDictionary(n=>n.Key,n=>U(n.Value,80));
        if(roots.Any(r=>!nodes.ContainsKey(r))) throw new IOException("Missing model root.");
        return new(rootKind,textures,amo,roots,nodes,tags);
    }
    static IEnumerable<uint> References(byte[] data,uint kind) {
        uint type=U(data);
        if(type==kind) {
            for(int i=0;i<U(data,4);++i) yield return U(data,12+i*4);
        } else if(type is 1 or 2 or 4 or 5 or 9 or 10) {
            foreach(var child in Children(data)) foreach(uint value in References(child,kind)) yield return value;
        }
    }
    static byte[] PatchMesh(byte[] source, Func<uint,uint> materialMap) {
        var data=(byte[])source.Clone();uint type=U(data);
        if(type==0x50000) {
            for(int i=0;i<U(data,4);++i) {
                uint old=U(data,12+i*4);
                Put(data,12+i*4,materialMap(old));
            }
        } else if(type is 1 or 2 or 4 or 5 or 9 or 10) {
            return Chunk(type,U(data,4),Children(data).Select(c=>PatchMesh(c,materialMap)));
        }
        return data;
    }
    static IEnumerable<Bank> AmmoBoxModels(List<Bank> banks) {
        var available=banks.SelectMany(b=>b.Roots.Select(r=>b.Tags[r])).ToHashSet();
        // These native ammunition definitions have inventory icons but no floor
        // mesh in any scenario. Give them an ordinary ammunition-box model;
        // their actual type, icon, rounds and weapon compatibility stay intact.
        foreach(var (type,box) in new[]{(201u,200u),(203u,200u),(209u,200u),(210u,200u),(251u,250u)}) {
            if(available.Contains(type)) continue;
            var source=banks.First(b=>b.Roots.Any(r=>b.Tags[r]==box));
            int ordinal=source.Roots.FindIndex(r=>source.Tags[r]==box);
            var mesh=Children(source.Amo.Single(c=>U(c)==2))[ordinal];
            var nodes=source.Nodes.Where(p=>source.Tags[p.Key]==box).ToDictionary(p=>p.Key,p=> {
                var node=(byte[])p.Value.Clone();Put(node,80,type);return node;
            });
            var amo=source.Amo.Select(c=>U(c)==2 ? Chunk(2,1,new[]{mesh}) : c).ToList();
            yield return new(source.RootKind,source.Textures,amo,new(){source.Roots[ordinal]},nodes,nodes.Keys.ToDictionary(i=>i,_=>type));
        }
    }
    static byte[] Merge(List<Bank> ordered, HashSet<ushort>? allowed = null) {
        var plans=new List<Plan>();var seen=new HashSet<uint>();
        foreach(var bank in ordered.Concat(AmmoBoxModels(ordered))) {
            bool first=plans.Count==0;
            var wanted=bank.Roots.Select(r=>bank.Tags[r])
                .Where(t=>first || t<600 && !seen.Contains(t) && (allowed == null || allowed.Contains((ushort)t))).ToHashSet();
            if(wanted.Count==0) continue;
            // World objects pair mesh ordinal with hierarchy-root ordinal. Their
            // authored joint-reference IDs do not index this scenario's AHI.
            var sourceMeshes=Children(bank.Amo.Single(c=>U(c)==2));
            if(sourceMeshes.Count!=bank.Roots.Count) throw new IOException("Object meshes and roots differ.");
            var meshes=sourceMeshes.Select((mesh,index)=>(Index:(uint)index,Mesh:mesh))
                .Where(m=>wanted.Contains(bank.Tags[bank.Roots[(int)m.Index]])).ToList();
            var selected=bank.Nodes.Keys.Where(i=>wanted.Contains(bank.Tags[i])).ToList();
            plans.Add(new(bank,wanted,selected,meshes));seen.UnionWith(wanted);
        }
        var textures=new List<byte[]>();var textureHash=new Dictionary<string,uint>();
        var meshesOut=new List<byte[]>();var materials=new List<byte[]>();var textureRefs=new List<byte[]>();
        var roots=new List<uint>();var nodesOut=new SortedDictionary<uint,byte[]>();
        uint selectedCursor=0;
        foreach(var plan in plans) {
            var bank=plan.Bank;var nodeMap=new Dictionary<uint,uint>();
            foreach(uint node in plan.Selected) nodeMap.Add(node,selectedCursor++);
            var textureMap=new Dictionary<uint,uint>();
            for(int i=0;i<bank.Textures.Count;++i) {
                string hash=Convert.ToHexString(SHA256.HashData(bank.Textures[i]));
                if(!textureHash.TryGetValue(hash,out uint mapped)) {
                    textureHash.Add(hash,mapped=(uint)textures.Count);textures.Add(bank.Textures[i]);
                }
                textureMap.Add((uint)i,mapped);
            }
            int materialBase=materials.Count,textureBase=textureRefs.Count;
            var meshMap=plan.Meshes.Select((m,i)=>(m.Index,New:(uint)(meshesOut.Count+i))).ToDictionary(m=>m.Index,m=>m.New);
            foreach(var (_,mesh) in plan.Meshes) meshesOut.Add(PatchMesh(mesh,old=>checked(old+(uint)materialBase)));
            foreach(var source in Children(bank.Amo.Single(c=>U(c)==9))) {
                var material=(byte[])source.Clone();uint count=U(material,64);
                if(count>32) throw new IOException("Too many material texture references.");
                for(int j=0;j<count;++j) Put(material,268+j*4,checked(U(material,268+j*4)+(uint)textureBase));
                materials.Add(material);
            }
            foreach(var source in Children(bank.Amo.Single(c=>U(c)==10))) {
                var texture=(byte[])source.Clone();Put(texture,12,textureMap[U(texture,12)]);textureRefs.Add(texture);
            }
            foreach(uint old in plan.Selected) {
                var node=(byte[])bank.Nodes[old].Clone();
                foreach(int pos in new[]{12,16,20,24}) if(U(node,pos)!=uint.MaxValue) Put(node,pos,nodeMap[U(node,pos)]);
                if(U(node,76)!=uint.MaxValue) Put(node,76,meshMap[U(node,76)]);
                nodesOut.Add(nodeMap[old],node);
            }
            roots.AddRange(bank.Roots.Where(r=>plan.Wanted.Contains(bank.Tags[r])).Select(r=>nodeMap[r]));
        }
        // The native material pool is shared by room, character and object
        // models. Loading unused materials can exhaust it and overwrite slot 0.
        var usedMaterials=meshesOut.SelectMany(m=>References(m,0x50000)).Distinct().Order().ToList();
        var materialMap=usedMaterials.Select((old,index)=>(old,New:(uint)index)).ToDictionary(p=>p.old,p=>p.New);
        materials=usedMaterials.Select(i=>materials[checked((int)i)]).ToList();
        var usedRefs=materials.SelectMany(m=>Enumerable.Range(0,checked((int)U(m,64)))
            .Select(i=>U(m,268+i*4))).Distinct().Order().ToList();
        var refMap=usedRefs.Select((old,index)=>(old,New:(uint)index)).ToDictionary(p=>p.old,p=>p.New);
        textureRefs=usedRefs.Select(i=>textureRefs[checked((int)i)]).ToList();
        var usedTextures=textureRefs.Select(t=>U(t,12)).Distinct().Order().ToList();
        var textureMapFinal=usedTextures.Select((old,index)=>(old,New:(uint)index)).ToDictionary(p=>p.old,p=>p.New);
        textures=usedTextures.Select(i=>textures[checked((int)i)]).ToList();
        meshesOut=meshesOut.Select(m=>PatchMesh(m,old=>materialMap[old])).ToList();
        foreach(var material in materials)
            for(int i=0;i<U(material,64);++i) Put(material,268+i*4,refMap[U(material,268+i*4)]);
        foreach(var texture in textureRefs) Put(texture,12,textureMapFinal[U(texture,12)]);
        if(roots.Count>96 || textures.Count>32 || nodesOut.Count>=1024 || meshesOut.Count!=roots.Count ||
           roots.Where((root,index)=>(index+1<roots.Count ? roots[index+1] : (uint)nodesOut.Count)-root>6).Any())
            throw new IOException($"Global object bank exceeds native capacity (roots={roots.Count}, textures={textures.Count}, nodes={nodesOut.Count}, meshes={meshesOut.Count}).");
        var date=ordered[0].Amo.Single(c=>U(c)==0x20000);
        byte[] amo=Chunk(1,4,new[]{date,Chunk(2,(uint)meshesOut.Count,meshesOut),
            Chunk(9,(uint)materials.Count,materials),Chunk(10,(uint)textureRefs.Count,textureRefs)});
        byte[] ahi=Chunk(0xc0000000,(uint)nodesOut.Count+1,
            new[]{Chunk(ordered[0].RootKind,(uint)roots.Count,new[]{Words(roots)})}.Concat(nodesOut.Values));
        using var stream=new MemoryStream();stream.Write(new byte[64]);
        var sections=new[]{("TEX\0",textures.SelectMany(b=>b).ToArray(),(uint)textures.Count),("AMO\0",amo,0u),("AHI\0",ahi,0u)};
        for(int i=0;i<sections.Length;++i) {
            while(stream.Length%64!=0) stream.WriteByte(0);
            var (name,bytes,count)=sections[i];long offset=stream.Position;stream.Write(bytes);
            long end=stream.Position;stream.Position=i*16;
            using(var writer=new BinaryWriter(stream,Encoding.ASCII,true)) {
                writer.Write(Encoding.ASCII.GetBytes(name));writer.Write((uint)offset);writer.Write(bytes.Length);writer.Write(count);
            }
            stream.Position=end;
        }
        while(stream.Length%64!=0) stream.WriteByte(0);
        if(stream.Length>2*1024*1024) throw new IOException("Global object bank exceeds the native read buffer.");
        return stream.ToArray();
    }
    internal static void Prepare(Dictionary<int,byte[]> sources,string logs, HashSet<ushort>? allowed = null) {
        var banks=sources.ToDictionary(p=>p.Key,p=>Parse(p.Value));
        string folder=Path.Combine(logs,"global-models");Directory.CreateDirectory(folder);
        foreach(var (number,bank) in banks) {
            var merged=Merge(new[]{bank}.Concat(banks.Where(p=>p.Key!=number).Select(p=>p.Value)).ToList(), allowed);
            File.WriteAllBytes(Path.Combine(folder,$"OBJS{number:00}.NBD"),merged);
        }
    }
}
