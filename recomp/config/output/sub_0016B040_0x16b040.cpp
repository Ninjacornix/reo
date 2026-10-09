#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B040
// Address: 0x16b040 - 0x16b0b0
void sub_0016B040_0x16b040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B040_0x16b040");
#endif

    switch (ctx->pc) {
        case 0x16b068u: goto label_16b068;
        case 0x16b078u: goto label_16b078;
        case 0x16b08cu: goto label_16b08c;
        default: break;
    }

    ctx->pc = 0x16b040u;

    // 0x16b040: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16b040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16b044: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b048: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16b048u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b04c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16b04cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16b050: 0x26111ae4  addiu       $s1, $s0, 0x1AE4
    ctx->pc = 0x16b050u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 6884));
    // 0x16b054: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16b054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16b058: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16b058u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16b05c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16b05cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16b060: 0xc059f40  jal         func_167D00
    ctx->pc = 0x16B060u;
    SET_GPR_U32(ctx, 31, 0x16B068u);
    ctx->pc = 0x16B064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B060u;
            // 0x16b064: 0x8e250018  lw          $a1, 0x18($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B068u; }
        if (ctx->pc != 0x16B068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D00_0x167d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B068u; }
        if (ctx->pc != 0x16B068u) { return; }
    }
    ctx->pc = 0x16B068u;
label_16b068:
    // 0x16b068: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b068u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b06c: 0x8e250014  lw          $a1, 0x14($s1)
    ctx->pc = 0x16b06cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x16b070: 0xc059f40  jal         func_167D00
    ctx->pc = 0x16B070u;
    SET_GPR_U32(ctx, 31, 0x16B078u);
    ctx->pc = 0x16B074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B070u;
            // 0x16b074: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B078u; }
        if (ctx->pc != 0x16B078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D00_0x167d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B078u; }
        if (ctx->pc != 0x16B078u) { return; }
    }
    ctx->pc = 0x16B078u;
label_16b078:
    // 0x16b078: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b078u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b07c: 0x8e25001c  lw          $a1, 0x1C($s1)
    ctx->pc = 0x16b07cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x16b080: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x16b080u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b084: 0xc059f40  jal         func_167D00
    ctx->pc = 0x16B084u;
    SET_GPR_U32(ctx, 31, 0x16B08Cu);
    ctx->pc = 0x16B088u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B084u;
            // 0x16b088: 0x2539024  and         $s2, $s2, $s3 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) & GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B08Cu; }
        if (ctx->pc != 0x16B08Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D00_0x167d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B08Cu; }
        if (ctx->pc != 0x16B08Cu) { return; }
    }
    ctx->pc = 0x16B08Cu;
label_16b08c:
    // 0x16b08c: 0x2421024  and         $v0, $s2, $v0
    ctx->pc = 0x16b08cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & GPR_U64(ctx, 2));
    // 0x16b090: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b090u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b094: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b094u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b098: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b098u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b09c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16b09cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b0a0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16b0a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16b0a4: 0x3e00008  jr          $ra
    ctx->pc = 0x16B0A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B0A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B0A4u;
            // 0x16b0a8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B068u: goto label_16b068;
            case 0x16B078u: goto label_16b078;
            case 0x16B08Cu: goto label_16b08c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B0ACu;
    // 0x16b0ac: 0x0  nop
    ctx->pc = 0x16b0acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
