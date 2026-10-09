#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148700
// Address: 0x148700 - 0x148760
void sub_00148700_0x148700(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148700_0x148700");
#endif

    switch (ctx->pc) {
        case 0x14871cu: goto label_14871c;
        default: break;
    }

    ctx->pc = 0x148700u;

    // 0x148700: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x148700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x148704: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x148704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x148708: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x148708u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14870c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x14870cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x148710: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x148710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x148714: 0xc050fe2  jal         func_143F88
    ctx->pc = 0x148714u;
    SET_GPR_U32(ctx, 31, 0x14871Cu);
    ctx->pc = 0x148718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148714u;
            // 0x148718: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x143F88u;
    if (runtime->hasFunction(0x143F88u)) {
        auto targetFn = runtime->lookupFunction(0x143F88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14871Cu; }
        if (ctx->pc != 0x14871Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00143F88_0x143f88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14871Cu; }
        if (ctx->pc != 0x14871Cu) { return; }
    }
    ctx->pc = 0x14871Cu;
label_14871c:
    // 0x14871c: 0x3c117000  lui         $s1, 0x7000
    ctx->pc = 0x14871cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)28672 << 16));
    // 0x148720: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x148720u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x148724: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x148724u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x148728: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x148728u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x14872c: 0x34421800  ori         $v0, $v0, 0x1800
    ctx->pc = 0x14872cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6144);
    // 0x148730: 0x34631b00  ori         $v1, $v1, 0x1B00
    ctx->pc = 0x148730u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)6912);
    // 0x148734: 0x34843300  ori         $a0, $a0, 0x3300
    ctx->pc = 0x148734u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)13056);
    // 0x148738: 0xae1105a8  sw          $s1, 0x5A8($s0)
    ctx->pc = 0x148738u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1448), GPR_U32(ctx, 17));
    // 0x14873c: 0xae0205ac  sw          $v0, 0x5AC($s0)
    ctx->pc = 0x14873cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1452), GPR_U32(ctx, 2));
    // 0x148740: 0xae0306e8  sw          $v1, 0x6E8($s0)
    ctx->pc = 0x148740u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1768), GPR_U32(ctx, 3));
    // 0x148744: 0xae0406ec  sw          $a0, 0x6EC($s0)
    ctx->pc = 0x148744u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1772), GPR_U32(ctx, 4));
    // 0x148748: 0xae000828  sw          $zero, 0x828($s0)
    ctx->pc = 0x148748u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2088), GPR_U32(ctx, 0));
    // 0x14874c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x14874cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x148750: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x148750u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x148754: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x148754u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x148758: 0x3e00008  jr          $ra
    ctx->pc = 0x148758u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14875Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148758u;
            // 0x14875c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14871Cu: goto label_14871c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148760u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
