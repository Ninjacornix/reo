#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010F930
// Address: 0x10f930 - 0x10f990
void sub_0010F930_0x10f930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010F930_0x10f930");
#endif

    switch (ctx->pc) {
        case 0x10f960u: goto label_10f960;
        default: break;
    }

    ctx->pc = 0x10f930u;

    // 0x10f930: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10f930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10f934: 0x3c020037  lui         $v0, 0x37
    ctx->pc = 0x10f934u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)55 << 16));
    // 0x10f938: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10f938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10f93c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10f93cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f940: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10f940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10f944: 0x2451f0dc  addiu       $s1, $v0, -0xF24
    ctx->pc = 0x10f944u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963420));
    // 0x10f948: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x10f948u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f94c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x10f94cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f950: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x10f950u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f954: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x10f954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x10f958: 0xc0452fa  jal         func_114BE8
    ctx->pc = 0x10F958u;
    SET_GPR_U32(ctx, 31, 0x10F960u);
    ctx->pc = 0x10F95Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F958u;
            // 0x10f95c: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114BE8u;
    if (runtime->hasFunction(0x114BE8u)) {
        auto targetFn = runtime->lookupFunction(0x114BE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F960u; }
        if (ctx->pc != 0x10F960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114BE8_0x114be8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F960u; }
        if (ctx->pc != 0x10F960u) { return; }
    }
    ctx->pc = 0x10F960u;
label_10f960:
    // 0x10f960: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x10f960u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f964: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x10f964u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10f968: 0x14640004  bne         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10F968u;
    {
        const bool branch_taken_0x10f968 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x10F96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F968u;
            // 0x10f96c: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f968) {
            ctx->pc = 0x10F97Cu;
            goto label_10f97c;
        }
    }
    ctx->pc = 0x10F970u;
    // 0x10f970: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x10f970u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x10f974: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10F974u;
    {
        const bool branch_taken_0x10f974 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f974) {
            ctx->pc = 0x10F978u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F974u;
            // 0x10f978: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F97Cu;
            goto label_10f97c;
        }
    }
    ctx->pc = 0x10F97Cu;
label_10f97c:
    // 0x10f97c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10f97cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10f980: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10f980u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10f984: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10f984u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10f988: 0x3e00008  jr          $ra
    ctx->pc = 0x10F988u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10F98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F988u;
            // 0x10f98c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10F960u: goto label_10f960;
            case 0x10F97Cu: goto label_10f97c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10F990u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
