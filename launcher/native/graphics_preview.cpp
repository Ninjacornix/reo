#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define REO_PREVIEW_EXPORTS
#include "graphics_preview.h"
#include <d3d11.h>
#include <d3dcompiler.h>
#include <dxgi1_3.h>
#include <wrl/client.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <string>
#include <vector>

using Microsoft::WRL::ComPtr;
namespace {
thread_local std::string lastError;
void check(HRESULT result, const char* operation) {
    if (FAILED(result)) {
        char value[32]; std::snprintf(value, sizeof(value), " (0x%08lX)", static_cast<unsigned long>(result));
        throw std::runtime_error(std::string(operation) + value);
    }
}
void require(bool condition, const char* message) { if (!condition) throw std::runtime_error(message); }
struct Vec { float x, y, z; };
Vec sub(Vec a, Vec b) { return {a.x-b.x,a.y-b.y,a.z-b.z}; }
Vec cross(Vec a, Vec b) { return {a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x}; }
Vec normal(Vec a) { float n=std::sqrt(a.x*a.x+a.y*a.y+a.z*a.z); return {a.x/n,a.y/n,a.z/n}; }
struct Vertex { float p[3], n[3], uv[2]; };
struct alignas(16) Constants {
    float right[4], up[4], forward[4], eye[4], projection[4], crop[4], surface[4];
    float extent[4], picture[4], window[4], view[4], tone[4], rotation[4], transition[4];
};
static_assert(sizeof(ReoPreviewOptions)==80 && sizeof(ReoPreviewStats)==40 && sizeof(Constants)%16==0, "Preview ABI/layout mismatch");

// Geometry, texture filtering, depth and all presentation passes execute on the
// hardware D3D11 device. The CPU only uploads skinned vertex attributes. There is
// no staging texture or GPU-to-CPU image copy in the production render path.
const char* shader = R"HLSL(
cbuffer Parameters : register(b0) {
    float4 cameraRight, cameraUp, cameraForward, eye;
    float4 projection, crop, surface, extent, picture, windowSize, viewRect, tone, rotation, transition;
};
Texture2D<float4> image : register(t0);
Texture2D<float2> edgeImage : register(t1);
SamplerState materialSampler : register(s0);
SamplerState presentationSampler : register(s1);
struct Input { float3 position : POSITION; float3 normal : NORMAL; float2 uv : TEXCOORD0; };
struct Geometry { float4 position : SV_Position; float2 uv : TEXCOORD0; float light : TEXCOORD1; float z : TEXCOORD2; };
float3 rotateActor(float3 p) {
    float sy=sin(rotation.x), cy=cos(rotation.x);
    return float3(p.x*cy+p.z*sy,p.y,-p.x*sy+p.z*cy);
}
Geometry GeometryVS(Input input) {
    Geometry output;
    float3 world=input.position, n=input.normal;
    if(surface.x>.5) { world=rotateActor(world-float3(0,.9,0))+float3(0,.9,0); n=rotateActor(n); }
    float3 relative=world-eye.xyz;
    float z=dot(relative,cameraForward.xyz);
    float2 ndc=float2(dot(relative,cameraRight.xyz)/(projection.x*projection.y),dot(relative,cameraUp.xyz)/projection.x);
    float2 uv=float2((ndc.x/z+1)*.5,(1-ndc.y/z)*.5);
    uv=(uv-crop.xy)/crop.zw;
    output.position=float4((uv.x*2-1)*z,(1-uv.y*2)*z,
        projection.w/(projection.w-projection.z)*z-projection.w*projection.z/(projection.w-projection.z),z);
    output.uv=input.uv;
    n=dot(n,n)>1e-8?normalize(n):float3(0,1,0);
    output.light=.31+.66*max(0,dot(n,normalize(float3(-.35,.85,.55))))+surface.x*.13;
    output.z=z;
    return output;
}
float4 GeometryPS(Geometry input) : SV_Target {
    float4 color=image.Sample(materialSampler,input.uv);
    clip(color.a-.35);
    float fog=clamp((input.z-4)/16,0,.65);
    return float4(lerp(color.rgb*input.light,float3(.055,.06,.065),fog),1);
}
float4 FullscreenVS(uint vertex : SV_VertexID) : SV_Position {
    float2 p=float2((vertex<<1)&2,vertex&2);
    return float4(p*float2(2,-2)+float2(-1,1),0,1);
}
int2 bounded(int2 p) { return clamp(p,int2(0,0),int2(extent.xy)-1); }
float3 loadColor(int2 p) { return image.Load(int3(bounded(p),0)).rgb; }
float4 EdgePS(float4 position : SV_Position) : SV_Target {
    int2 p=int2(position.xy); float3 c=loadColor(p), left=c-loadColor(p-int2(1,0)), above=c-loadColor(p-int2(0,1));
    return float4(dot(left,left)>.0144,dot(above,above)>.0144,0,1);
}
float2 readEdge(int2 p) { return edgeImage.Load(int3(bounded(p),0)); }
float coverage(int2 p,int axis) {
    float2 e=readEdge(p); if((axis==0?e.x:e.y)<.5) return 0;
    int2 along=axis==0?int2(0,1):int2(1,0);
    int a=0,b=0;
    [loop] for(int i=1;i<=16;i++) { float2 v=readEdge(p-along*i); if((axis==0?v.x:v.y)<.5) break; a++; }
    [loop] for(int j=1;j<=16;j++) { float2 v=readEdge(p+along*j); if((axis==0?v.x:v.y)<.5) break; b++; }
    return .5*(1-abs(a-b)/float(a+b+2));
}
// Morphological edge search with analytic coverage, like the launcher's earlier
// preview. The gameplay SMAA backend uses its separate precomputed area LUT.
float4 MorphologyPS(float4 position : SV_Position) : SV_Target {
    int2 p=int2(position.xy); float3 result=loadColor(p); float weight=1;
    float left=coverage(p,0), above=coverage(p,1);
    result+=loadColor(p-int2(1,0))*left+loadColor(p-int2(0,1))*above; weight+=left+above;
    result/=weight;
    float right=coverage(p+int2(1,0),0)*.5, below=coverage(p+int2(0,1),1)*.5;
    result=lerp(result,loadColor(p+int2(1,0)),right);
    result=lerp(result,loadColor(p+int2(0,1)),below);
    return float4(result,1);
}
float luminance(float3 c) { return dot(c,float3(.299,.587,.114)); }
float3 readColor(float2 uv) { return image.SampleLevel(presentationSampler,uv,0).rgb; }
float3 fxaa(float2 uv,float2 stepSize) {
    float3 middle=readColor(uv); float center=luminance(middle);
    float nw=luminance(readColor(uv+float2(-1,-1)*stepSize)), ne=luminance(readColor(uv+float2(1,-1)*stepSize));
    float sw=luminance(readColor(uv+float2(-1,1)*stepSize)), se=luminance(readColor(uv+float2(1,1)*stepSize));
    float low=min(center,min(min(nw,ne),min(sw,se))), high=max(center,max(max(nw,ne),max(sw,se)));
    if(high-low<max(.03125,high*.125)) return middle;
    float2 direction=float2(sw+se-nw-ne,nw+sw-ne-se);
    float reduction=max((nw+ne+sw+se)*.03125,.0078125);
    direction=clamp(direction/(min(abs(direction.x),abs(direction.y))+reduction),-8,8)*stepSize;
    float3 narrow=(readColor(uv-direction/6)+readColor(uv+direction/6))*.5;
    float3 wide=narrow*.5+(readColor(uv-direction*.5)+readColor(uv+direction*.5))*.25;
    float wideLuma=luminance(wide);
    return wideLuma<low||wideLuma>high?narrow:wide;
}
float4 PresentPS(float4 position : SV_Position) : SV_Target {
    float2 virtualPixel;
    if(windowSize.z>.5) virtualPixel=viewRect.xy+position.xy/extent.zw*viewRect.zw;
    else {
        float scale=min(extent.z/windowSize.x,extent.w/windowSize.y);
        float2 border=(extent.zw-windowSize.xy*scale)*.5;
        virtualPixel=(position.xy-border)/scale;
        if(any(virtualPixel<0)||any(virtualPixel>=windowSize.xy)) return float4(transition.yzw*(1-transition.x),1);
    }
    float2 quantized=floor(virtualPixel)+.5;
    float2 uv=((quantized-picture.xy)/picture.zw-crop.xy)/crop.zw;
    if(windowSize.z<.5&&(any(uv<0)||any(uv>=1))) return float4(transition.yzw*(1-transition.x),1);
    uv=saturate(uv);
    float3 color;
    if(tone.z>.5&&tone.z<1.5) {
        float scale=min(extent.z/windowSize.x,extent.w/windowSize.y);
        float2 steps=windowSize.z>.5?1/extent.zw:1/(picture.zw*scale*crop.zw);
        color=fxaa(uv,steps);
    } else if(tone.w>.5) color=readColor(uv);
    else color=image.Load(int3(min(int2(uv*extent.xy),int2(extent.xy)-1),0)).rgb;
    return float4(lerp(transition.yzw,pow(saturate(color*tone.x),tone.y),transition.x),1);
}
)HLSL";

struct Mesh {
    ComPtr<ID3D11Buffer> vertices, indices;
    std::vector<Vertex> source;
    UINT indexCount=0;
    int texture=-1;
    bool character=false;
};
struct Texture { ComPtr<ID3D11Texture2D> resource; ComPtr<ID3D11ShaderResourceView> view; };
struct Target { ComPtr<ID3D11Texture2D> resource; ComPtr<ID3D11RenderTargetView> target; ComPtr<ID3D11ShaderResourceView> view; };
struct Query {
    ComPtr<ID3D11Query> disjoint, begin, end;
    bool pending=false;
    uint64_t serial=0;
};
struct WaitHandle {
    HANDLE value=nullptr;
    ~WaitHandle() { if(value) CloseHandle(value); }
    WaitHandle()=default;
    WaitHandle(const WaitHandle&)=delete;
    WaitHandle& operator=(const WaitHandle&)=delete;
};
class Renderer {
public:
    std::mutex mutex;
    std::string deviceName;
    ReoPreviewStats stats{};
    explicit Renderer(HWND window) : window_(window) {
        require(IsWindow(window)!=FALSE,"The GPU preview needs a valid child window.");
        D3D_FEATURE_LEVEL levels[]={D3D_FEATURE_LEVEL_11_1,D3D_FEATURE_LEVEL_11_0};
        D3D_FEATURE_LEVEL feature{};
        HRESULT created=D3D11CreateDevice(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr,D3D11_CREATE_DEVICE_BGRA_SUPPORT,
            levels,2,D3D11_SDK_VERSION,&device_,&feature,&context_);
        if(created==E_INVALIDARG) created=D3D11CreateDevice(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr,D3D11_CREATE_DEVICE_BGRA_SUPPORT,
            levels+1,1,D3D11_SDK_VERSION,&device_,&feature,&context_);
        check(created,"Create hardware Direct3D 11 device");
        stats.feature_level=static_cast<uint32_t>(feature); stats.hardware=1; stats.gpu_milliseconds=-1;
        ComPtr<IDXGIDevice> dxgi; check(device_.As(&dxgi),"Query DXGI device");
        ComPtr<IDXGIAdapter> adapter; check(dxgi->GetAdapter(&adapter),"Get hardware adapter");
        ComPtr<IDXGIAdapter1> adapter1;check(adapter.As(&adapter1),"Inspect hardware adapter type");
        DXGI_ADAPTER_DESC1 description{};check(adapter1->GetDesc1(&description),"Read hardware adapter name");
        require((description.Flags&DXGI_ADAPTER_FLAG_SOFTWARE)==0,"The preview requires a hardware GPU adapter; software adapters are not used.");
        int count=WideCharToMultiByte(CP_UTF8,0,description.Description,-1,nullptr,0,nullptr,nullptr);
        require(count>0,"The GPU adapter has no name."); deviceName.resize(static_cast<size_t>(count));
        WideCharToMultiByte(CP_UTF8,0,description.Description,-1,deviceName.data(),count,nullptr,nullptr);
        if(!deviceName.empty()&&deviceName.back()==0) deviceName.pop_back();
        ComPtr<IDXGIFactory2> factory; check(adapter->GetParent(IID_PPV_ARGS(&factory)),"Get hardware DXGI factory");
        RECT client{}; GetClientRect(window,&client);
        UINT width=static_cast<UINT>(std::max<LONG>(1,client.right)),height=static_cast<UINT>(std::max<LONG>(1,client.bottom));
        DXGI_SWAP_CHAIN_DESC1 swap{}; swap.Width=width;swap.Height=height;swap.Format=DXGI_FORMAT_B8G8R8A8_UNORM;
        // One additional flip buffer prevents a nonblocking present from losing
        // a display interval while WPF and DWM finish using the previous image.
        swap.SampleDesc.Count=1;swap.BufferUsage=DXGI_USAGE_RENDER_TARGET_OUTPUT;swap.BufferCount=3;
        swap.Scaling=DXGI_SCALING_STRETCH;swap.SwapEffect=DXGI_SWAP_EFFECT_FLIP_DISCARD;swap.AlphaMode=DXGI_ALPHA_MODE_IGNORE;
        swap.Flags=DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT;
        check(factory->CreateSwapChainForHwnd(device_.Get(),window,&swap,nullptr,nullptr,&swapchain_),"Create preview GPU swapchain");
        ComPtr<IDXGISwapChain2> paced;check(swapchain_.As(&paced),"Get preview presentation pacing");
        check(paced->SetMaximumFrameLatency(1),"Set preview presentation latency");
        frameLatency_.value=paced->GetFrameLatencyWaitableObject();
        require(frameLatency_.value!=nullptr,"The preview swapchain has no frame-latency signal.");
        check(factory->MakeWindowAssociation(window,DXGI_MWA_NO_ALT_ENTER),"Set preview window association");
        compileShaders(); createStates(); createWhite();
        for(auto& query:queries_) {
            D3D11_QUERY_DESC descriptor{D3D11_QUERY_TIMESTAMP_DISJOINT,0};
            check(device_->CreateQuery(&descriptor,&query.disjoint),"Create GPU disjoint query");
            descriptor.Query=D3D11_QUERY_TIMESTAMP;
            check(device_->CreateQuery(&descriptor,&query.begin),"Create GPU start timestamp");
            check(device_->CreateQuery(&descriptor,&query.end),"Create GPU end timestamp");
        }
        resize(width,height);
    }
    ~Renderer() { if(context_) { context_->ClearState(); context_->Flush(); } }
    void resize(int width,int height) {
        require(width>0&&height>0&&width<=8192&&height<=8192,"Invalid GPU preview viewport size.");
        if(stats.output_width==static_cast<UINT>(width)&&stats.output_height==static_cast<UINT>(height)) return;
        unbind(); backbuffer_.Reset(); final_=Target{}; staging_.Reset();
        check(swapchain_->ResizeBuffers(0,width,height,DXGI_FORMAT_UNKNOWN,DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT),"Resize preview swapchain");
        check(swapchain_->GetBuffer(0,IID_PPV_ARGS(&backbuffer_)),"Get preview GPU backbuffer");
        final_=target(width,height,DXGI_FORMAT_B8G8R8A8_UNORM);
        stats.output_width=width;stats.output_height=height;
    }
    void clearScene() { unbind(); meshes_.clear(); textures_.clear(); }
    int frameReady() {
        if(occluded_) {
            HRESULT visible=swapchain_->Present(0,DXGI_PRESENT_TEST);
            if(visible==DXGI_STATUS_OCCLUDED) return 0;
            check(visible,"Check preview presentation visibility");occluded_=false;
        }
        DWORD state=WaitForSingleObject(frameLatency_.value,0);
        if(state==WAIT_OBJECT_0) return 1;
        if(state==WAIT_TIMEOUT) {
            check(device_->GetDeviceRemovedReason(),"The preview GPU device was removed");return 0;
        }
        if(state==WAIT_FAILED) check(HRESULT_FROM_WIN32(GetLastError()),"Poll preview presentation readiness");
        throw std::runtime_error("Unexpected preview presentation readiness state.");
    }
    int createTexture(int width,int height,const uint8_t* rgba) {
        require(rgba&&width>0&&height>0&&width<=4096&&height<=4096&&textures_.size()<512,"Invalid GPU preview texture.");
        D3D11_TEXTURE2D_DESC descriptor{}; descriptor.Width=width;descriptor.Height=height;descriptor.MipLevels=0;descriptor.ArraySize=1;
        descriptor.Format=DXGI_FORMAT_R8G8B8A8_UNORM;descriptor.SampleDesc.Count=1;
        descriptor.Usage=D3D11_USAGE_DEFAULT;descriptor.BindFlags=D3D11_BIND_SHADER_RESOURCE|D3D11_BIND_RENDER_TARGET;
        descriptor.MiscFlags=D3D11_RESOURCE_MISC_GENERATE_MIPS;
        Texture texture; check(device_->CreateTexture2D(&descriptor,nullptr,&texture.resource),"Create model GPU texture");
        context_->UpdateSubresource(texture.resource.Get(),0,nullptr,rgba,width*4,0);
        check(device_->CreateShaderResourceView(texture.resource.Get(),nullptr,&texture.view),"Create model texture view");
        context_->GenerateMips(texture.view.Get());
        textures_.push_back(std::move(texture)); return static_cast<int>(textures_.size()-1);
    }
    int createMesh(const float* positions,const float* normals,const float* uv,int vertices,const uint32_t* indices,
                   int count,int textureId,bool character) {
        require(positions&&normals&&uv&&indices&&vertices>=3&&vertices<=200000&&count>=3&&count<=600000&&count%3==0&&meshes_.size()<256,
            "Invalid GPU preview mesh.");
        require(textureId>=-1&&textureId<static_cast<int>(textures_.size()),"Unknown GPU preview mesh texture.");
        Mesh mesh;mesh.source.resize(vertices);mesh.indexCount=count;mesh.texture=textureId;mesh.character=character;
        for(int i=0;i<vertices;i++) {
            for(int axis=0;axis<3;axis++) {
                require(std::isfinite(positions[i*3+axis])&&std::isfinite(normals[i*3+axis]),"Non-finite GPU preview vertex.");
                mesh.source[i].p[axis]=positions[i*3+axis];mesh.source[i].n[axis]=normals[i*3+axis];
            }
            for(int axis=0;axis<2;axis++) { require(std::isfinite(uv[i*2+axis]),"Non-finite GPU preview UV.");mesh.source[i].uv[axis]=uv[i*2+axis]; }
        }
        for(int i=0;i<count;i++) require(indices[i]<static_cast<UINT>(vertices),"GPU preview triangle index is outside its mesh.");
        D3D11_BUFFER_DESC descriptor{};descriptor.ByteWidth=vertices*sizeof(Vertex);descriptor.Usage=D3D11_USAGE_DYNAMIC;
        descriptor.BindFlags=D3D11_BIND_VERTEX_BUFFER;descriptor.CPUAccessFlags=D3D11_CPU_ACCESS_WRITE;
        D3D11_SUBRESOURCE_DATA data{};data.pSysMem=mesh.source.data();
        check(device_->CreateBuffer(&descriptor,&data,&mesh.vertices),"Create animated GPU vertex buffer");
        descriptor.ByteWidth=count*sizeof(uint32_t);descriptor.Usage=D3D11_USAGE_IMMUTABLE;
        descriptor.BindFlags=D3D11_BIND_INDEX_BUFFER;descriptor.CPUAccessFlags=0;data.pSysMem=indices;
        check(device_->CreateBuffer(&descriptor,&data,&mesh.indices),"Create GPU triangle index buffer");
        meshes_.push_back(std::move(mesh));return static_cast<int>(meshes_.size()-1);
    }
    void updateMesh(int id,const float* positions,const float* normals) {
        require(id>=0&&id<static_cast<int>(meshes_.size())&&positions&&normals,"Invalid animated GPU mesh update.");
        auto& mesh=meshes_[id];
        for(size_t i=0;i<mesh.source.size();i++) for(int axis=0;axis<3;axis++) {
            require(std::isfinite(positions[i*3+axis])&&std::isfinite(normals[i*3+axis]),"Non-finite animated GPU vertex.");
            mesh.source[i].p[axis]=positions[i*3+axis];mesh.source[i].n[axis]=normals[i*3+axis];
        }
        D3D11_MAPPED_SUBRESOURCE mapped{};check(context_->Map(mesh.vertices.Get(),0,D3D11_MAP_WRITE_DISCARD,0,&mapped),"Upload animated GPU mesh");
        std::memcpy(mapped.pData,mesh.source.data(),mesh.source.size()*sizeof(Vertex));context_->Unmap(mesh.vertices.Get(),0);
    }
    int render(const ReoPreviewOptions& requested) {
        ReoPreviewOptions option=requested;
        option.internal_resolution=option.internal_resolution==2||option.internal_resolution==4?option.internal_resolution:1;
        option.anisotropy=option.anisotropy==2||option.anisotropy==4||option.anisotropy==8||option.anisotropy==16?option.anisotropy:1;
        option.antialiasing=std::clamp(option.antialiasing,0,2);option.aspect=std::clamp(option.aspect,0,3);
        option.screen_fit=std::clamp(option.screen_fit,0,3);option.brightness=std::clamp(option.brightness,50,150);
        option.gamma=std::isfinite(option.gamma)?std::clamp(option.gamma,.5f,2.f):1.f;
        option.window_width=std::clamp(option.window_width,256,7680);option.window_height=std::clamp(option.window_height,224,4320);
        option.yaw=std::isfinite(option.yaw)?std::remainder(option.yaw,360.f):0;
        option.pitch=0; // Inspection rotates around the upright vertical axis only.
        option.zoom=std::isfinite(option.zoom)&&option.zoom>0?std::clamp(option.zoom,.65f,2.5f):1.f;
        updateConstants(option);
        int width=std::max(1,static_cast<int>(std::ceil(512*option.internal_resolution*constants_.crop[2])));
        int height=std::max(1,static_cast<int>(std::ceil(448*option.internal_resolution*constants_.crop[3])));
        if(width!=static_cast<int>(stats.render_width)||height!=static_cast<int>(stats.render_height)) resizeScene(width,height);
        constants_.extent[0]=static_cast<float>(width);constants_.extent[1]=static_cast<float>(height);
        pollQueries();Query* query=nullptr;
        for(size_t i=0;i<queries_.size();i++) {
            auto& candidate=queries_[(nextQuery_+i)%queries_.size()];
            if(!candidate.pending) { query=&candidate;nextQuery_=(nextQuery_+i+1)%queries_.size();break; }
        }
        if(query) {query->serial=++issuedQuery_;context_->Begin(query->disjoint.Get());context_->End(query->begin.Get());}
        unbind();viewport(width,height);
        const float background[]={.055f,.06f,.065f,1};context_->ClearRenderTargetView(scene_.target.Get(),background);
        context_->ClearDepthStencilView(depthView_.Get(),D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL,1,0);
        ID3D11RenderTargetView* color=scene_.target.Get();context_->OMSetRenderTargets(1,&color,depthView_.Get());
        context_->OMSetDepthStencilState(depthState_.Get(),0);context_->RSSetState(rasterState_.Get());
        context_->IASetInputLayout(layout_.Get());context_->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        context_->VSSetShader(geometryVS_.Get(),nullptr,0);context_->PSSetShader(geometryPS_.Get(),nullptr,0);
        ID3D11SamplerState* sampler=option.anisotropy>1?anisotropic_[anisoIndex(option.anisotropy)].Get()
            :option.texture_linear?linearWrap_.Get():pointWrap_.Get();
        context_->PSSetSamplers(0,1,&sampler);
        for(auto& mesh:meshes_) {
            constants_.surface[0]=mesh.character?1.f:0.f;uploadConstants();
            UINT stride=sizeof(Vertex),offset=0;ID3D11Buffer* buffer=mesh.vertices.Get();
            context_->IASetVertexBuffers(0,1,&buffer,&stride,&offset);context_->IASetIndexBuffer(mesh.indices.Get(),DXGI_FORMAT_R32_UINT,0);
            ID3D11ShaderResourceView* texture=mesh.texture<0?white_.Get():textures_[mesh.texture].view.Get();
            context_->PSSetShaderResources(0,1,&texture);context_->DrawIndexed(mesh.indexCount,0,0);
        }
        unbind();context_->OMSetDepthStencilState(noDepth_.Get(),0);context_->IASetInputLayout(nullptr);
        context_->VSSetShader(fullscreenVS_.Get(),nullptr,0);uploadConstants();
        if(option.antialiasing==2) {
            fullscreen(edges_.target.Get(),edgePS_.Get(),scene_.view.Get(),nullptr);
            fullscreen(morphology_.target.Get(),morphologyPS_.Get(),scene_.view.Get(),edges_.view.Get());
        }
        viewport(stats.output_width,stats.output_height);
        ID3D11SamplerState* presentation=(option.output_linear||option.antialiasing==1)?linearClamp_.Get():pointClamp_.Get();
        context_->PSSetSamplers(1,1,&presentation);
        fullscreen(final_.target.Get(),presentPS_.Get(),option.antialiasing==2?morphology_.view.Get():scene_.view.Get(),nullptr);
        unbind();context_->CopyResource(backbuffer_.Get(),final_.resource.Get());
        if(query) {context_->End(query->end.Get());context_->End(query->disjoint.Get());query->pending=true;}
        HRESULT presented=swapchain_->Present(0,DXGI_PRESENT_DO_NOT_WAIT);
        if(presented==DXGI_STATUS_OCCLUDED) {occluded_=true;return 2;}
        if(presented==DXGI_ERROR_WAS_STILL_DRAWING) return 2;
        if(FAILED(presented)) {
            HRESULT removed=device_->GetDeviceRemovedReason();
            if(FAILED(removed)) check(removed,"The preview GPU device was removed");
            check(presented,"Present GPU preview");
        }
        occluded_=false;stats.frames_presented++;return 1;
    }
    void readback(uint8_t* output,int bytes) {
        require(output&&bytes>=0&&static_cast<uint64_t>(bytes)>=static_cast<uint64_t>(stats.output_width)*stats.output_height*4,
            "Diagnostic GPU readback buffer is too small.");
        if(!staging_) {
            D3D11_TEXTURE2D_DESC descriptor{};final_.resource->GetDesc(&descriptor);descriptor.Usage=D3D11_USAGE_STAGING;
            descriptor.BindFlags=0;descriptor.MiscFlags=0;descriptor.CPUAccessFlags=D3D11_CPU_ACCESS_READ;
            check(device_->CreateTexture2D(&descriptor,nullptr,&staging_),"Create diagnostic GPU staging texture");
        }
        context_->CopyResource(staging_.Get(),final_.resource.Get());
        D3D11_MAPPED_SUBRESOURCE mapped{};check(context_->Map(staging_.Get(),0,D3D11_MAP_READ,0,&mapped),"Read diagnostic GPU image");
        for(UINT y=0;y<stats.output_height;y++) std::memcpy(output+static_cast<size_t>(y)*stats.output_width*4,
            static_cast<const uint8_t*>(mapped.pData)+static_cast<size_t>(y)*mapped.RowPitch,stats.output_width*4);
        context_->Unmap(staging_.Get(),0);pollQueries();
    }
    void pollQueries() {
        for(auto& query:queries_) if(query.pending) {
            D3D11_QUERY_DATA_TIMESTAMP_DISJOINT disjoint{};UINT64 begin=0,end=0;
            HRESULT available=context_->GetData(query.disjoint.Get(),&disjoint,sizeof(disjoint),D3D11_ASYNC_GETDATA_DONOTFLUSH);
            if(available==S_FALSE) continue;check(available,"Read GPU timestamp readiness");
            HRESULT first=context_->GetData(query.begin.Get(),&begin,sizeof(begin),D3D11_ASYNC_GETDATA_DONOTFLUSH),
                last=context_->GetData(query.end.Get(),&end,sizeof(end),D3D11_ASYNC_GETDATA_DONOTFLUSH);
            if(first==S_FALSE||last==S_FALSE) continue;
            check(first,"Read GPU start timestamp");check(last,"Read GPU end timestamp");
            if(!disjoint.Disjoint&&disjoint.Frequency&&end>=begin&&query.serial>latestQuery_) {
                stats.gpu_milliseconds=(end-begin)*1000.0/disjoint.Frequency;latestQuery_=query.serial;
            }
            query.pending=false;
        }
    }
private:
    HWND window_{};
    WaitHandle frameLatency_;
    bool occluded_=false;
    ComPtr<ID3D11Device> device_;ComPtr<ID3D11DeviceContext> context_;ComPtr<IDXGISwapChain1> swapchain_;
    ComPtr<ID3D11Texture2D> backbuffer_,depth_,staging_;ComPtr<ID3D11DepthStencilView> depthView_;
    Target scene_,edges_,morphology_,final_;
    ComPtr<ID3D11VertexShader> geometryVS_,fullscreenVS_;
    ComPtr<ID3D11PixelShader> geometryPS_,edgePS_,morphologyPS_,presentPS_;
    ComPtr<ID3D11InputLayout> layout_;ComPtr<ID3D11Buffer> constantBuffer_;
    ComPtr<ID3D11DepthStencilState> depthState_,noDepth_;ComPtr<ID3D11RasterizerState> rasterState_;
    ComPtr<ID3D11SamplerState> pointWrap_,linearWrap_,pointClamp_,linearClamp_;
    std::array<ComPtr<ID3D11SamplerState>,4> anisotropic_;
    ComPtr<ID3D11ShaderResourceView> white_;
    std::vector<Texture> textures_;std::vector<Mesh> meshes_;std::array<Query,8> queries_;size_t nextQuery_=0;
    uint64_t issuedQuery_=0,latestQuery_=0;
    Constants constants_{};
    static int anisoIndex(int value) { return value==2?0:value==4?1:value==8?2:3; }
    ComPtr<ID3DBlob> compile(const char* entry,const char* target) {
        ComPtr<ID3DBlob> output,error;
        HRESULT result=D3DCompile(shader,std::strlen(shader),"Reo.GraphicsPreview",nullptr,nullptr,entry,target,
            D3DCOMPILE_ENABLE_STRICTNESS|D3DCOMPILE_OPTIMIZATION_LEVEL3,0,&output,&error);
        if(FAILED(result)&&error) throw std::runtime_error(std::string("Compile preview ")+entry+": "+
            std::string(static_cast<const char*>(error->GetBufferPointer()),error->GetBufferSize()));
        check(result,"Compile preview GPU shader");return output;
    }
    void compileShaders() {
        auto vertex=compile("GeometryVS","vs_5_0");
        check(device_->CreateVertexShader(vertex->GetBufferPointer(),vertex->GetBufferSize(),nullptr,&geometryVS_),"Create model vertex shader");
        const D3D11_INPUT_ELEMENT_DESC elements[]={
            {"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
            {"NORMAL",0,DXGI_FORMAT_R32G32B32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0},
            {"TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,0,24,D3D11_INPUT_PER_VERTEX_DATA,0}};
        check(device_->CreateInputLayout(elements,3,vertex->GetBufferPointer(),vertex->GetBufferSize(),&layout_),"Create model input layout");
        vertex=compile("FullscreenVS","vs_5_0");
        check(device_->CreateVertexShader(vertex->GetBufferPointer(),vertex->GetBufferSize(),nullptr,&fullscreenVS_),"Create preview fullscreen shader");
        auto pixel=[&](const char* entry,ComPtr<ID3D11PixelShader>& destination) {
            auto code=compile(entry,"ps_5_0");check(device_->CreatePixelShader(code->GetBufferPointer(),code->GetBufferSize(),nullptr,&destination),entry);
        };
        pixel("GeometryPS",geometryPS_);pixel("EdgePS",edgePS_);pixel("MorphologyPS",morphologyPS_);pixel("PresentPS",presentPS_);
    }
    void createStates() {
        D3D11_BUFFER_DESC descriptor{};descriptor.ByteWidth=sizeof(Constants);descriptor.Usage=D3D11_USAGE_DYNAMIC;
        descriptor.BindFlags=D3D11_BIND_CONSTANT_BUFFER;descriptor.CPUAccessFlags=D3D11_CPU_ACCESS_WRITE;
        check(device_->CreateBuffer(&descriptor,nullptr,&constantBuffer_),"Create preview GPU constants");
        D3D11_DEPTH_STENCIL_DESC depth{};depth.DepthEnable=TRUE;depth.DepthWriteMask=D3D11_DEPTH_WRITE_MASK_ALL;depth.DepthFunc=D3D11_COMPARISON_LESS;
        check(device_->CreateDepthStencilState(&depth,&depthState_),"Create preview depth testing");
        depth.DepthEnable=FALSE;depth.DepthWriteMask=D3D11_DEPTH_WRITE_MASK_ZERO;
        check(device_->CreateDepthStencilState(&depth,&noDepth_),"Create presentation depth state");
        D3D11_RASTERIZER_DESC raster{};raster.FillMode=D3D11_FILL_SOLID;raster.CullMode=D3D11_CULL_NONE;raster.DepthClipEnable=TRUE;
        check(device_->CreateRasterizerState(&raster,&rasterState_),"Create preview GPU rasterizer");
        auto sampler=[&](D3D11_FILTER filter,D3D11_TEXTURE_ADDRESS_MODE address,UINT anisotropy,bool mips,ComPtr<ID3D11SamplerState>& result) {
            D3D11_SAMPLER_DESC state{};state.Filter=filter;state.AddressU=state.AddressV=state.AddressW=address;
            state.MaxAnisotropy=anisotropy;state.ComparisonFunc=D3D11_COMPARISON_NEVER;state.MinLOD=0;state.MaxLOD=mips?D3D11_FLOAT32_MAX:0;
            check(device_->CreateSamplerState(&state,&result),"Create preview GPU sampler");
        };
        sampler(D3D11_FILTER_MIN_MAG_MIP_POINT,D3D11_TEXTURE_ADDRESS_WRAP,1,false,pointWrap_);
        sampler(D3D11_FILTER_MIN_MAG_MIP_LINEAR,D3D11_TEXTURE_ADDRESS_WRAP,1,false,linearWrap_);
        sampler(D3D11_FILTER_MIN_MAG_MIP_POINT,D3D11_TEXTURE_ADDRESS_CLAMP,1,false,pointClamp_);
        sampler(D3D11_FILTER_MIN_MAG_MIP_LINEAR,D3D11_TEXTURE_ADDRESS_CLAMP,1,false,linearClamp_);
        for(int i=0;i<4;i++) sampler(D3D11_FILTER_ANISOTROPIC,D3D11_TEXTURE_ADDRESS_WRAP,2u<<i,true,anisotropic_[i]);
    }
    void createWhite() {
        uint32_t pixel=0xffffffff;D3D11_TEXTURE2D_DESC descriptor{};descriptor.Width=descriptor.Height=descriptor.MipLevels=descriptor.ArraySize=1;
        descriptor.Format=DXGI_FORMAT_R8G8B8A8_UNORM;descriptor.SampleDesc.Count=1;descriptor.Usage=D3D11_USAGE_IMMUTABLE;
        descriptor.BindFlags=D3D11_BIND_SHADER_RESOURCE;D3D11_SUBRESOURCE_DATA initial{&pixel,4,0};ComPtr<ID3D11Texture2D> texture;
        check(device_->CreateTexture2D(&descriptor,&initial,&texture),"Create default GPU texture");
        check(device_->CreateShaderResourceView(texture.Get(),nullptr,&white_),"Create default GPU texture view");
    }
    Target target(int width,int height,DXGI_FORMAT format) {
        Target output;D3D11_TEXTURE2D_DESC descriptor{};descriptor.Width=width;descriptor.Height=height;descriptor.MipLevels=descriptor.ArraySize=1;
        descriptor.Format=format;descriptor.SampleDesc.Count=1;descriptor.Usage=D3D11_USAGE_DEFAULT;
        descriptor.BindFlags=D3D11_BIND_RENDER_TARGET|D3D11_BIND_SHADER_RESOURCE;
        check(device_->CreateTexture2D(&descriptor,nullptr,&output.resource),"Create preview GPU render target");
        check(device_->CreateRenderTargetView(output.resource.Get(),nullptr,&output.target),"Create preview render-target view");
        check(device_->CreateShaderResourceView(output.resource.Get(),nullptr,&output.view),"Create preview scene view");return output;
    }
    void resizeScene(int width,int height) {
        require(width>0&&height>0&&width<=4096&&height<=4096,"Invalid internal GPU preview resolution.");unbind();
        scene_=target(width,height,DXGI_FORMAT_R8G8B8A8_UNORM);
        edges_=target(width,height,DXGI_FORMAT_R8G8_UNORM);morphology_=target(width,height,DXGI_FORMAT_R8G8B8A8_UNORM);
        D3D11_TEXTURE2D_DESC descriptor{};descriptor.Width=width;descriptor.Height=height;descriptor.MipLevels=descriptor.ArraySize=1;
        descriptor.Format=DXGI_FORMAT_D24_UNORM_S8_UINT;descriptor.SampleDesc.Count=1;descriptor.Usage=D3D11_USAGE_DEFAULT;
        descriptor.BindFlags=D3D11_BIND_DEPTH_STENCIL;depthView_.Reset();depth_.Reset();
        check(device_->CreateTexture2D(&descriptor,nullptr,&depth_),"Create GPU preview depth buffer");
        check(device_->CreateDepthStencilView(depth_.Get(),nullptr,&depthView_),"Create GPU preview depth view");
        stats.render_width=width;stats.render_height=height;
    }
    void unbind() {
        context_->OMSetRenderTargets(0,nullptr,nullptr);ID3D11ShaderResourceView* empty[]={nullptr,nullptr};
        context_->PSSetShaderResources(0,2,empty);
    }
    void viewport(UINT width,UINT height) {
        D3D11_VIEWPORT viewport{};viewport.Width=static_cast<float>(width);viewport.Height=static_cast<float>(height);viewport.MaxDepth=1;
        context_->RSSetViewports(1,&viewport);
    }
    void uploadConstants() {
        D3D11_MAPPED_SUBRESOURCE mapped{};check(context_->Map(constantBuffer_.Get(),0,D3D11_MAP_WRITE_DISCARD,0,&mapped),"Update GPU preview constants");
        std::memcpy(mapped.pData,&constants_,sizeof(constants_));context_->Unmap(constantBuffer_.Get(),0);
        ID3D11Buffer* buffer=constantBuffer_.Get();context_->VSSetConstantBuffers(0,1,&buffer);context_->PSSetConstantBuffers(0,1,&buffer);
    }
    void fullscreen(ID3D11RenderTargetView* target,ID3D11PixelShader* pixel,ID3D11ShaderResourceView* image,ID3D11ShaderResourceView* edges) {
        unbind();context_->OMSetRenderTargets(1,&target,nullptr);ID3D11ShaderResourceView* views[]={image,edges};
        context_->PSSetShaderResources(0,2,views);context_->PSSetShader(pixel,nullptr,0);context_->Draw(3,0);
    }
    void updateConstants(const ReoPreviewOptions& option) {
        constants_=Constants{};
        Vec eye{2.8f,1.55f,4.4f},forward=normal(sub({0,.95f,0},eye)),right=normal(cross(forward,{0,1,0})),up=cross(right,forward);
        auto set=[](float* destination,Vec value) {destination[0]=value.x;destination[1]=value.y;destination[2]=value.z;};
        set(constants_.right,right);set(constants_.up,up);set(constants_.forward,forward);set(constants_.eye,eye);
        const float aspects[]={4.f/3,16.f/9,43.f/18,32.f/9};float aspect=aspects[option.aspect];
        constants_.projection[0]=std::tan(32.f*3.14159265358979323846f/360)/option.zoom;constants_.projection[1]=option.widescreen?aspect:4.f/3;
        constants_.projection[2]=.08f;constants_.projection[3]=40;
        float ww=static_cast<float>(option.window_width),wh=static_cast<float>(option.window_height),pw=ww,ph=wh;
        if(option.screen_fit!=2) {
            if(option.screen_fit==1) {ph=std::min(448.f*option.internal_resolution,std::min(ww/aspect,wh));pw=ph*aspect;}
            else if((ww/wh>aspect)!=(option.screen_fit==3)) pw=ph*aspect;
            else ph=pw/aspect;
        }
        float px=(ww-pw)*.5f,py=(wh-ph)*.5f,vx=0,vy=0,vw=ww,vh=wh;
        if(option.cover) {
            vx=std::max(0.f,px);vy=std::max(0.f,py);
            float activeW=std::min(ww,px+pw)-vx,activeH=std::min(wh,py+ph)-vy;
            float ratio=static_cast<float>(stats.output_width)/stats.output_height;
            vw=std::min(activeW,activeH*ratio);vh=std::min(activeH,activeW/ratio);
            vx+=(activeW-vw)*.5f;vy+=(activeH-vh)*.5f;
            constants_.crop[0]=(vx-px)/pw;constants_.crop[1]=(vy-py)/ph;constants_.crop[2]=vw/pw;constants_.crop[3]=vh/ph;
        } else {constants_.crop[2]=constants_.crop[3]=1;}
        constants_.picture[0]=px;constants_.picture[1]=py;constants_.picture[2]=pw;constants_.picture[3]=ph;
        constants_.window[0]=ww;constants_.window[1]=wh;constants_.window[2]=option.cover?1.f:0.f;
        constants_.view[0]=vx;constants_.view[1]=vy;constants_.view[2]=vw;constants_.view[3]=vh;
        constants_.extent[2]=static_cast<float>(stats.output_width);constants_.extent[3]=static_cast<float>(stats.output_height);
        constants_.tone[0]=option.brightness/100.f;constants_.tone[1]=1.f/option.gamma;
        constants_.transition[0]=std::clamp(option.opacity,0.f,1.f);
        constants_.transition[1]=option.background_r;constants_.transition[2]=option.background_g;constants_.transition[3]=option.background_b;
        constants_.tone[2]=static_cast<float>(option.antialiasing);constants_.tone[3]=option.output_linear?1.f:0.f;
        constants_.rotation[0]=option.yaw*3.14159265358979323846f/180;constants_.rotation[1]=option.pitch*3.14159265358979323846f/180;
    }
};
Renderer& renderer(void* handle) { require(handle!=nullptr,"The GPU preview is not initialized.");return *static_cast<Renderer*>(handle); }
template<class Operation> int invoke(void* handle,Operation operation) noexcept {
    try {lastError.clear();auto& value=renderer(handle);std::lock_guard<std::mutex> guard(value.mutex);return operation(value);}
    catch(const std::exception& error) {lastError=error.what();return 0;}catch(...) {lastError="Unknown GPU preview failure.";return 0;}
}
}

extern "C" REO_PREVIEW_API void* reo_preview_create(HWND window) {
    try {lastError.clear();return new Renderer(window);}catch(const std::exception& error) {lastError=error.what();return nullptr;}
    catch(...) {lastError="Unknown GPU preview initialization failure.";return nullptr;}
}
extern "C" REO_PREVIEW_API void reo_preview_destroy(void* handle) {delete static_cast<Renderer*>(handle);}
extern "C" REO_PREVIEW_API int reo_preview_resize(void* handle,int width,int height) {return invoke(handle,[&](Renderer& r) {r.resize(width,height);return 1;});}
extern "C" REO_PREVIEW_API void reo_preview_clear_scene(void* handle) {invoke(handle,[](Renderer& r) {r.clearScene();return 1;});}
extern "C" REO_PREVIEW_API int reo_preview_create_texture(void* handle,int width,int height,const uint8_t* rgba) {
    int result=-1;return invoke(handle,[&](Renderer& r) {result=r.createTexture(width,height,rgba);return 1;})?result:-1;
}
extern "C" REO_PREVIEW_API int reo_preview_create_mesh(void* handle,const float* positions,const float* normals,const float* uv,
    int vertex_count,const uint32_t* indices,int index_count,int texture_id,int character) {
    int result=-1;return invoke(handle,[&](Renderer& r) {result=r.createMesh(positions,normals,uv,vertex_count,indices,index_count,texture_id,character!=0);return 1;})?result:-1;
}
extern "C" REO_PREVIEW_API int reo_preview_update_mesh(void* handle,int mesh_id,const float* positions,const float* normals) {
    return invoke(handle,[&](Renderer& r) {r.updateMesh(mesh_id,positions,normals);return 1;});
}
extern "C" REO_PREVIEW_API int reo_preview_frame_ready(void* handle) {
    int ready=-1;return invoke(handle,[&](Renderer& r) {ready=r.frameReady();return 1;})?ready:-1;
}
extern "C" REO_PREVIEW_API int reo_preview_render(void* handle,const ReoPreviewOptions* options) {
    return invoke(handle,[&](Renderer& r) {require(options!=nullptr,"Missing GPU preview settings.");return r.render(*options);});
}
extern "C" REO_PREVIEW_API int reo_preview_readback(void* handle,uint8_t* bgra,int byte_count) {
    return invoke(handle,[&](Renderer& r) {r.readback(bgra,byte_count);return 1;});
}
extern "C" REO_PREVIEW_API int reo_preview_get_stats(void* handle,ReoPreviewStats* stats) {
    return invoke(handle,[&](Renderer& r) {require(stats!=nullptr,"Missing GPU statistics output.");r.pollQueries();*stats=r.stats;return 1;});
}
extern "C" REO_PREVIEW_API const char* reo_preview_device_name(void* handle) {
    try {return renderer(handle).deviceName.c_str();}catch(const std::exception& error) {lastError=error.what();return "";}
}
extern "C" REO_PREVIEW_API const char* reo_preview_last_error() {return lastError.c_str();}
