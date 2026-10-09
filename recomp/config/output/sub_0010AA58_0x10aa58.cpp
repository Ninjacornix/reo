#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010AA58
// Address: 0x10aa58 - 0x10aabc
void sub_0010AA58_0x10aa58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010AA58_0x10aa58");
#endif

    switch (ctx->pc) {
        case 0x10aa7cu: goto label_10aa7c;
        default: break;
    }

    ctx->pc = 0x10aa58u;

    // 0x10aa58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10aa58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10aa5c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x10aa5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa60: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10aa60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10aa64: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10aa64u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa68: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x10aa68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x10aa6c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x10aa6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa70: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10aa70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10aa74: 0xc041abe  jal         func_106AF8
    ctx->pc = 0x10AA74u;
    SET_GPR_U32(ctx, 31, 0x10AA7Cu);
    ctx->pc = 0x10AA78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA74u;
            // 0x10aa78: 0x8605000e  lh          $a1, 0xE($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106AF8u;
    if (runtime->hasFunction(0x106AF8u)) {
        auto targetFn = runtime->lookupFunction(0x106AF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA7Cu; }
        if (ctx->pc != 0x10AA7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106AF8_0x106af8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10AA7Cu; }
        if (ctx->pc != 0x10AA7Cu) { return; }
    }
    ctx->pc = 0x10AA7Cu;
label_10aa7c:
    // 0x10aa7c: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x10aa7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10aa80: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x10aa80u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10aa84: 0x3283c  dsll32      $a1, $v1, 0
    ctx->pc = 0x10aa84u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x10aa88: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x10aa88u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x10aa8c: 0x14640004  bne         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10AA8Cu;
    {
        const bool branch_taken_0x10aa8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x10AA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA8Cu;
            // 0x10aa90: 0x9603000c  lhu         $v1, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10aa8c) {
            ctx->pc = 0x10AAA0u;
            goto label_10aaa0;
        }
    }
    ctx->pc = 0x10AA94u;
    // 0x10aa94: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x10AA94u;
    {
        const bool branch_taken_0x10aa94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10AA98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AA94u;
            // 0x10aa98: 0x3063efff  andi        $v1, $v1, 0xEFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)61439);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10aa94) {
            ctx->pc = 0x10AAA8u;
            goto label_10aaa8;
        }
    }
    ctx->pc = 0x10AA9Cu;
    // 0x10aa9c: 0x0  nop
    ctx->pc = 0x10aa9cu;
    // NOP
label_10aaa0:
    // 0x10aaa0: 0xae050050  sw          $a1, 0x50($s0)
    ctx->pc = 0x10aaa0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 5));
    // 0x10aaa4: 0x34631000  ori         $v1, $v1, 0x1000
    ctx->pc = 0x10aaa4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4096);
label_10aaa8:
    // 0x10aaa8: 0xa603000c  sh          $v1, 0xC($s0)
    ctx->pc = 0x10aaa8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x10aaac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10aaacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10aab0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x10aab0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10aab4: 0x3e00008  jr          $ra
    ctx->pc = 0x10AAB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10AAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AAB4u;
            // 0x10aab8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10AA7Cu: goto label_10aa7c;
            case 0x10AAA0u: goto label_10aaa0;
            case 0x10AAA8u: goto label_10aaa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10AABCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
