#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179930
// Address: 0x179930 - 0x179990
void sub_00179930_0x179930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179930_0x179930");
#endif

    switch (ctx->pc) {
        case 0x179954u: goto label_179954;
        case 0x17996cu: goto label_17996c;
        case 0x179978u: goto label_179978;
        default: break;
    }

    ctx->pc = 0x179930u;

    // 0x179930: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179934: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x179934u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x179938: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17993c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17993cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179940: 0x24450e08  addiu       $a1, $v0, 0xE08
    ctx->pc = 0x179940u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 3592));
    // 0x179944: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179948: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17994c: 0xc042e02  jal         func_10B808
    ctx->pc = 0x17994Cu;
    SET_GPR_U32(ctx, 31, 0x179954u);
    ctx->pc = 0x179950u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17994Cu;
            // 0x179950: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B808u;
    if (runtime->hasFunction(0x10B808u)) {
        auto targetFn = runtime->lookupFunction(0x10B808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179954u; }
        if (ctx->pc != 0x179954u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B808_0x10b808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179954u; }
        if (ctx->pc != 0x179954u) { return; }
    }
    ctx->pc = 0x179954u;
label_179954:
    // 0x179954: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179954u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179958: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x179958u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17995c: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17995Cu;
    {
        const bool branch_taken_0x17995c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x179960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17995Cu;
            // 0x179960: 0x24640004  addiu       $a0, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17995c) {
            ctx->pc = 0x17997Cu;
            goto label_17997c;
        }
    }
    ctx->pc = 0x179964u;
    // 0x179964: 0xc05e664  jal         func_179990
    ctx->pc = 0x179964u;
    SET_GPR_U32(ctx, 31, 0x17996Cu);
    ctx->pc = 0x179990u;
    if (runtime->hasFunction(0x179990u)) {
        auto targetFn = runtime->lookupFunction(0x179990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17996Cu; }
        if (ctx->pc != 0x17996Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179990_0x179990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17996Cu; }
        if (ctx->pc != 0x17996Cu) { return; }
    }
    ctx->pc = 0x17996Cu;
label_17996c:
    // 0x17996c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17996cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179970: 0xc05e664  jal         func_179990
    ctx->pc = 0x179970u;
    SET_GPR_U32(ctx, 31, 0x179978u);
    ctx->pc = 0x179974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179970u;
            // 0x179974: 0x24440001  addiu       $a0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179990u;
    if (runtime->hasFunction(0x179990u)) {
        auto targetFn = runtime->lookupFunction(0x179990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179978u; }
        if (ctx->pc != 0x179978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179990_0x179990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179978u; }
        if (ctx->pc != 0x179978u) { return; }
    }
    ctx->pc = 0x179978u;
label_179978:
    // 0x179978: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179978u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_17997c:
    // 0x17997c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17997cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179980: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179980u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179984: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179984u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179988: 0x3e00008  jr          $ra
    ctx->pc = 0x179988u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17998Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179988u;
            // 0x17998c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179954u: goto label_179954;
            case 0x17996Cu: goto label_17996c;
            case 0x179978u: goto label_179978;
            case 0x17997Cu: goto label_17997c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179990u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
