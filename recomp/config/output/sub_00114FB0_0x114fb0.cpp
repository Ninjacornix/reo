#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114FB0
// Address: 0x114fb0 - 0x115058
void sub_00114FB0_0x114fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114FB0_0x114fb0");
#endif

    switch (ctx->pc) {
        case 0x114fc0u: goto label_114fc0;
        default: break;
    }

    ctx->pc = 0x114fb0u;

    // 0x114fb0: 0x3c07ffff  lui         $a3, 0xFFFF
    ctx->pc = 0x114fb0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)65535 << 16));
    // 0x114fb4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x114fb4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x114fb8: 0x34e7f000  ori         $a3, $a3, 0xF000
    ctx->pc = 0x114fb8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)61440);
    // 0x114fbc: 0x0  nop
    ctx->pc = 0x114fbcu;
    // NOP
label_114fc0:
    // 0x114fc0: 0xf  sync
    ctx->pc = 0x114fc0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114fc4: 0xbcd00000  cache       0x10, 0x0($a2)
    ctx->pc = 0x114fc4u;
    // CACHE instruction (ignored)
    // 0x114fc8: 0xf  sync
    ctx->pc = 0x114fc8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114fcc: 0x4002e000  mfc0        $v0, TagLo
    ctx->pc = 0x114fccu;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_taglo);
    // 0x114fd0: 0x471024  and         $v0, $v0, $a3
    ctx->pc = 0x114fd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 7));
    // 0x114fd4: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x114fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x114fd8: 0xa2182b  sltu        $v1, $a1, $v0
    ctx->pc = 0x114fd8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x114fdc: 0x44102b  sltu        $v0, $v0, $a0
    ctx->pc = 0x114fdcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x114fe0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x114FE0u;
    {
        const bool branch_taken_0x114fe0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x114fe0) {
            ctx->pc = 0x114FFCu;
            goto label_114ffc;
        }
    }
    ctx->pc = 0x114FE8u;
    // 0x114fe8: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x114FE8u;
    {
        const bool branch_taken_0x114fe8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x114fe8) {
            ctx->pc = 0x114FFCu;
            goto label_114ffc;
        }
    }
    ctx->pc = 0x114FF0u;
    // 0x114ff0: 0xf  sync
    ctx->pc = 0x114ff0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114ff4: 0xbcd60000  cache       0x16, 0x0($a2)
    ctx->pc = 0x114ff4u;
    // CACHE instruction (ignored)
    // 0x114ff8: 0xf  sync
    ctx->pc = 0x114ff8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
label_114ffc:
    // 0x114ffc: 0xf  sync
    ctx->pc = 0x114ffcu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x115000: 0xbcd00001  cache       0x10, 0x1($a2)
    ctx->pc = 0x115000u;
    // CACHE instruction (ignored)
    // 0x115004: 0xf  sync
    ctx->pc = 0x115004u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x115008: 0x4002e000  mfc0        $v0, TagLo
    ctx->pc = 0x115008u;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_taglo);
    // 0x11500c: 0x471024  and         $v0, $v0, $a3
    ctx->pc = 0x11500cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 7));
    // 0x115010: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x115010u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x115014: 0xa2182b  sltu        $v1, $a1, $v0
    ctx->pc = 0x115014u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x115018: 0x44102b  sltu        $v0, $v0, $a0
    ctx->pc = 0x115018u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x11501c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11501Cu;
    {
        const bool branch_taken_0x11501c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11501c) {
            ctx->pc = 0x115038u;
            goto label_115038;
        }
    }
    ctx->pc = 0x115024u;
    // 0x115024: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x115024u;
    {
        const bool branch_taken_0x115024 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x115024) {
            ctx->pc = 0x115038u;
            goto label_115038;
        }
    }
    ctx->pc = 0x11502Cu;
    // 0x11502c: 0xf  sync
    ctx->pc = 0x11502cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x115030: 0xbcd60001  cache       0x16, 0x1($a2)
    ctx->pc = 0x115030u;
    // CACHE instruction (ignored)
    // 0x115034: 0xf  sync
    ctx->pc = 0x115034u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
label_115038:
    // 0x115038: 0xf  sync
    ctx->pc = 0x115038u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11503c: 0x24c60040  addiu       $a2, $a2, 0x40
    ctx->pc = 0x11503cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
    // 0x115040: 0x28c21000  slti        $v0, $a2, 0x1000
    ctx->pc = 0x115040u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4096) ? 1 : 0);
    // 0x115044: 0x1440ffde  bnez        $v0, . + 4 + (-0x22 << 2)
    ctx->pc = 0x115044u;
    {
        const bool branch_taken_0x115044 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x115044) {
            ctx->pc = 0x114FC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_114fc0;
        }
    }
    ctx->pc = 0x11504Cu;
    // 0x11504c: 0x3e00008  jr          $ra
    ctx->pc = 0x11504Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x114FC0u: goto label_114fc0;
            case 0x114FFCu: goto label_114ffc;
            case 0x115038u: goto label_115038;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115054u;
    // 0x115054: 0x0  nop
    ctx->pc = 0x115054u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
