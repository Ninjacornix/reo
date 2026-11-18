
// V2 extends the SAME playback selection. V1 remains PCM-only and intentionally
// retains its original legacy-bank compatibility; it is not a V2 fallback.
#define PS2_RUNTIME_HAS_AUDIO_BANK_BACKEND_DISPATCH 1
namespace backend_detail { struct Binding; }
enum class BankStatusV2 { ok, rejected, closed, unsupported, invalid_input,
    invalid_asset, capacity, no_memory, stale_generation, foreign_runtime };
struct BankQueryV2 { BankStatusV2 status{BankStatusV2::closed};std::uint32_t value{}; };
class SoundCall;
using AudioSetupOperationV2=void (*)(void*,const SoundCall&) noexcept;
class SoundCallScope final {
public:
    explicit SoundCallScope(const SoundCall&) noexcept;
    ~SoundCallScope();
    SoundCallScope(const SoundCallScope&)=delete;
    SoundCallScope& operator=(const SoundCallScope&)=delete;
private:
    backend_detail::Binding* previous_{};
};
// Allocation-free whole-call ownership. Acquire before any recognized sound
// RPC adoption/payload read; retain through response and completion effects.
// Release before caller-initiated join. Do not retain across threads or destroy
// concurrently. Explicit methods reuse this admission even after stop.
class SoundCall final {
public:
    SoundCall() noexcept=default;
    SoundCall(SoundCall&&) noexcept;
    SoundCall& operator=(SoundCall&&) noexcept;
    ~SoundCall();
    SoundCall(const SoundCall&)=delete;
    SoundCall& operator=(const SoundCall&)=delete;
    BankStatusV2 status() const noexcept{return status_;}
    explicit operator bool() const noexcept{return status_==BankStatusV2::ok;}
    bool native() const noexcept{return !legacy_&&bool(binding_);}
    BankStatusV2 ensure_output() const;
    BankStatusV2 reset_pcm() const;
    BankStatusV2 submit_bank(unsigned,const std::uint8_t*,std::size_t,const std::uint8_t*,std::size_t,const std::uint8_t*,std::size_t) const;
    BankStatusV2 submit_packet(const std::uint8_t*,std::size_t,const std::uint8_t*,std::size_t) const;
    BankStatusV2 mix(float*,unsigned) const;
    BankStatusV2 reset_banks() const;
    BankQueryV2 pending_loads() const;
    BankQueryV2 port_state(unsigned,std::uint32_t&) const;
    BankQueryV2 se_state(unsigned,unsigned,unsigned) const;
    BankStatusV2 report_audio_paths() const;
private:
    friend SoundCall acquireSoundCall(PS2Runtime*) noexcept;
    friend SoundCall acquireSoundControlCall(PS2Runtime*) noexcept;
    friend bool withAudioSetupBeforeRun(PS2Runtime&,AudioSetupOperationV2,void*) noexcept;
    friend class SoundCallScope;
    void release() noexcept;
    std::shared_ptr<backend_detail::Binding> binding_;
    BankStatusV2 status_{BankStatusV2::closed};
    bool legacy_{},admitted_{},setup_{},control_{};
};
// A nonnull runtime must match the published V2 runtime before admission or any
// side effect. Null is for the process-selected public bank facade only.
SoundCall acquireSoundCall(PS2Runtime* runtime=nullptr) noexcept;
// Metadata control does not select unselected playback. Its reservation prevents
// installation/setup publication, not ordinary first use. Such an unselected
// token cannot invoke bank/PCM methods. Published V2 control ALWAYS requires
// nonnull exact runtime identity; legacy/V1 metadata behavior is retained.
SoundCall acquireSoundControlCall(PS2Runtime* runtime) noexcept;
// Execute the complete pre-run metadata/reset operation while BOTH runtime
// phase and shared boot-reset publication reservation are retained. Operation
// receives a borrowed const setup capability and must not retain it/reenter a
// public facade. Registry/runtime locks are not held across the operation.
bool withAudioSetupBeforeRun(PS2Runtime&,AudioSetupOperationV2,void*) noexcept;
// Pure primitive classification; unrecognized traffic does not select audio.
bool coversSoundRpcV2(std::uint32_t sid,std::uint32_t rpc) noexcept;
struct BankApiV2 {
    BankStatusV2 (*submit_bank)(void*,unsigned,const std::uint8_t*,std::size_t,const std::uint8_t*,std::size_t,const std::uint8_t*,std::size_t) noexcept{};
    BankStatusV2 (*submit_packet)(void*,const std::uint8_t*,std::size_t,const std::uint8_t*,std::size_t) noexcept{};
    BankStatusV2 (*mix)(void*,float*,unsigned) noexcept{};
    BankStatusV2 (*reset)(void*) noexcept{};
    BankQueryV2 (*pending_loads)(void*) noexcept{};
    BankQueryV2 (*port_state)(void*,unsigned,std::uint32_t&) noexcept{};
    BankQueryV2 (*se_state)(void*,unsigned,unsigned,unsigned) noexcept{};
    BankStatusV2 (*report_audio_paths)(void*) noexcept{};
};
using AdmittedRenderV2=void (*)(void*,SoundCall&,float*,unsigned) noexcept;
constexpr std::uint32_t backendAbiVersionV2=2;
constexpr std::uint64_t backendRequiredCapabilitiesV2=backendRequiredCapabilitiesV1|(0xFFull<<32);
struct BackendApiV2 {
    std::uint32_t abi_version{},structure_bytes{};
    std::uint64_t capabilities{};
    BackendApiV1 pcm;
    BankApiV2 banks;
    // Receives the outer admission. Its bank stage MUST use this token rather
    // than entering a newly closed gate or stopping the inner bank core early.
    AdmittedRenderV2 render_admitted{};
};
struct BackendRegistrationV2 { BackendApiV2 api;std::shared_ptr<void> owner; };
BackendInstallStatusV1 installBackendBeforeRunV2(PS2Runtime&,BackendRegistrationV2) noexcept;
// Explicit setup only: same runtime phase lease and shared boot reservation as
// PCM setup. Ordinary bank reset is a first use and seals legacy.
bool resetBanksBeforeRuntimeRun(PS2Runtime&) noexcept;
