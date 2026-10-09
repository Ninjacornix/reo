#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A2F0
// Address: 0x10a2f0 - 0x10a380
void sub_0010A2F0_0x10a2f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A2F0_0x10a2f0");
#endif

    ctx->pc = 0x10a2f0u;

    // 0x10a2f0: 0x44066000  mfc1        $a2, $f12
    ctx->pc = 0x10a2f0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x10a2f4: 0x615c3  sra         $v0, $a2, 23
    ctx->pc = 0x10a2f4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 6), 23));
    // 0x10a2f8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x10a2f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x10a2fc: 0x2445ff81  addiu       $a1, $v0, -0x7F
    ctx->pc = 0x10a2fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967169));
    // 0x10a300: 0x28a30017  slti        $v1, $a1, 0x17
    ctx->pc = 0x10a300u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)23) ? 1 : 0);
    // 0x10a304: 0x10600016  beqz        $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x10A304u;
    {
        const bool branch_taken_0x10a304 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A304u;
            // 0x10a308: 0x27bdfff0  addiu       $sp, $sp, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a304) {
            ctx->pc = 0x10A360u;
            goto label_10a360;
        }
    }
    ctx->pc = 0x10A30Cu;
    // 0x10a30c: 0x4a10008  bgez        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x10A30Cu;
    {
        const bool branch_taken_0x10a30c = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x10A310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A30Cu;
            // 0x10a310: 0x3c02007f  lui         $v0, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a30c) {
            ctx->pc = 0x10A330u;
            goto label_10a330;
        }
    }
    ctx->pc = 0x10A314u;
    // 0x10a314: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x10a314u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x10a318: 0xc23024  and         $a2, $a2, $v0
    ctx->pc = 0x10a318u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x10a31c: 0xafa60000  sw          $a2, 0x0($sp)
    ctx->pc = 0x10a31cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    // 0x10a320: 0xc7a00000  lwc1        $f0, 0x0($sp)
    ctx->pc = 0x10a320u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x10a324: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x10A324u;
    {
        const bool branch_taken_0x10a324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A324u;
            // 0x10a328: 0xe4800000  swc1        $f0, 0x0($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a324) {
            ctx->pc = 0x10A370u;
            goto label_10a370;
        }
    }
    ctx->pc = 0x10A32Cu;
    // 0x10a32c: 0x0  nop
    ctx->pc = 0x10a32cu;
    // NOP
label_10a330:
    // 0x10a330: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10a330u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10a334: 0xa21007  srav        $v0, $v0, $a1
    ctx->pc = 0x10a334u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x10a338: 0x21827  nor         $v1, $zero, $v0
    ctx->pc = 0x10a338u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x10a33c: 0xc21024  and         $v0, $a2, $v0
    ctx->pc = 0x10a33cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x10a340: 0xc31824  and         $v1, $a2, $v1
    ctx->pc = 0x10a340u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x10a344: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10A344u;
    {
        const bool branch_taken_0x10a344 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A344u;
            // 0x10a348: 0xafa30004  sw          $v1, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a344) {
            ctx->pc = 0x10A360u;
            goto label_10a360;
        }
    }
    ctx->pc = 0x10A34Cu;
    // 0x10a34c: 0xc7a00004  lwc1        $f0, 0x4($sp)
    ctx->pc = 0x10a34cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x10a350: 0xe4800000  swc1        $f0, 0x0($a0)
    ctx->pc = 0x10a350u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x10a354: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x10A354u;
    {
        const bool branch_taken_0x10a354 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A354u;
            // 0x10a358: 0x46006001  sub.s       $f0, $f12, $f0 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[12], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a354) {
            ctx->pc = 0x10A374u;
            goto label_10a374;
        }
    }
    ctx->pc = 0x10A35Cu;
    // 0x10a35c: 0x0  nop
    ctx->pc = 0x10a35cu;
    // NOP
label_10a360:
    // 0x10a360: 0xe48c0000  swc1        $f12, 0x0($a0)
    ctx->pc = 0x10a360u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x10a364: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x10a364u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x10a368: 0xc23024  and         $a2, $a2, $v0
    ctx->pc = 0x10a368u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x10a36c: 0x44866000  mtc1        $a2, $f12
    ctx->pc = 0x10a36cu;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
label_10a370:
    // 0x10a370: 0x46006006  mov.s       $f0, $f12
    ctx->pc = 0x10a370u;
    ctx->f[0] = FPU_MOV_S(ctx->f[12]);
label_10a374:
    // 0x10a374: 0x3e00008  jr          $ra
    ctx->pc = 0x10A374u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A374u;
            // 0x10a378: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A330u: goto label_10a330;
            case 0x10A360u: goto label_10a360;
            case 0x10A370u: goto label_10a370;
            case 0x10A374u: goto label_10a374;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A37Cu;
    // 0x10a37c: 0x0  nop
    ctx->pc = 0x10a37cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
