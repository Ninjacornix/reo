#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148DB8
// Address: 0x148db8 - 0x148e98
void sub_00148DB8_0x148db8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148DB8_0x148db8");
#endif

    ctx->pc = 0x148db8u;

    // 0x148db8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x148db8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x148dbc: 0x3c0e0fff  lui         $t6, 0xFFF
    ctx->pc = 0x148dbcu;
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)4095 << 16));
    // 0x148dc0: 0x8fa20078  lw          $v0, 0x78($sp)
    ctx->pc = 0x148dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x148dc4: 0x35ceffff  ori         $t6, $t6, 0xFFFF
    ctx->pc = 0x148dc4u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) | (uint64_t)(uint16_t)65535);
    // 0x148dc8: 0x8fa30070  lw          $v1, 0x70($sp)
    ctx->pc = 0x148dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x148dcc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x148dccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x148dd0: 0x621818  mult        $v1, $v1, $v0
    ctx->pc = 0x148dd0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x148dd4: 0x2410ffff  addiu       $s0, $zero, -0x1
    ctx->pc = 0x148dd4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x148dd8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x148dd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x148ddc: 0x24120180  addiu       $s2, $zero, 0x180
    ctx->pc = 0x148ddcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
    // 0x148de0: 0x8fac0058  lw          $t4, 0x58($sp)
    ctx->pc = 0x148de0u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x148de4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x148de4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x148de8: 0x203802a  slt         $s0, $s0, $v1
    ctx->pc = 0x148de8u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x148dec: 0x246201ff  addiu       $v0, $v1, 0x1FF
    ctx->pc = 0x148decu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x148df0: 0x70100b  movn        $v0, $v1, $s0
    ctx->pc = 0x148df0u;
    if (GPR_U64(ctx, 16) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x148df4: 0x18e8824  and         $s1, $t4, $t6
    ctx->pc = 0x148df4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 12) & GPR_U64(ctx, 14));
    // 0x148df8: 0x21243  sra         $v0, $v0, 9
    ctx->pc = 0x148df8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 9));
    // 0x148dfc: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x148dfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x148e00: 0x521818  mult        $v1, $v0, $s2
    ctx->pc = 0x148e00u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x148e04: 0x8fad0060  lw          $t5, 0x60($sp)
    ctx->pc = 0x148e04u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x148e08: 0x3c132000  lui         $s3, 0x2000
    ctx->pc = 0x148e08u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)8192 << 16));
    // 0x148e0c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x148e0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x148e10: 0x8fb40068  lw          $s4, 0x68($sp)
    ctx->pc = 0x148e10u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x148e14: 0x2338825  or          $s1, $s1, $s3
    ctx->pc = 0x148e14u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 19));
    // 0x148e18: 0x1ae7824  and         $t7, $t5, $t6
    ctx->pc = 0x148e18u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 13) & GPR_U64(ctx, 14));
    // 0x148e1c: 0xac910000  sw          $s1, 0x0($a0)
    ctx->pc = 0x148e1cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 17));
    // 0x148e20: 0x6c6021  addu        $t4, $v1, $t4
    ctx->pc = 0x148e20u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x148e24: 0x1f37825  or          $t7, $t7, $s3
    ctx->pc = 0x148e24u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) | GPR_U64(ctx, 19));
    // 0x148e28: 0x521818  mult        $v1, $v0, $s2
    ctx->pc = 0x148e28u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x148e2c: 0x522018  mult        $a0, $v0, $s2
    ctx->pc = 0x148e2cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x148e30: 0xacaf0000  sw          $t7, 0x0($a1)
    ctx->pc = 0x148e30u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 15));
    // 0x148e34: 0x18e6024  and         $t4, $t4, $t6
    ctx->pc = 0x148e34u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & GPR_U64(ctx, 14));
    // 0x148e38: 0x1936025  or          $t4, $t4, $s3
    ctx->pc = 0x148e38u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | GPR_U64(ctx, 19));
    // 0x148e3c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x148e3cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x148e40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x148e40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x148e44: 0x6d6821  addu        $t5, $v1, $t5
    ctx->pc = 0x148e44u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 13)));
    // 0x148e48: 0x941021  addu        $v0, $a0, $s4
    ctx->pc = 0x148e48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 20)));
    // 0x148e4c: 0x28e1824  and         $v1, $s4, $t6
    ctx->pc = 0x148e4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & GPR_U64(ctx, 14));
    // 0x148e50: 0x1ae6824  and         $t5, $t5, $t6
    ctx->pc = 0x148e50u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) & GPR_U64(ctx, 14));
    // 0x148e54: 0x731825  or          $v1, $v1, $s3
    ctx->pc = 0x148e54u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 19));
    // 0x148e58: 0x4e1024  and         $v0, $v0, $t6
    ctx->pc = 0x148e58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 14));
    // 0x148e5c: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x148e5cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x148e60: 0x1b36825  or          $t5, $t5, $s3
    ctx->pc = 0x148e60u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) | GPR_U64(ctx, 19));
    // 0x148e64: 0xacf10000  sw          $s1, 0x0($a3)
    ctx->pc = 0x148e64u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 17));
    // 0x148e68: 0x531025  or          $v0, $v0, $s3
    ctx->pc = 0x148e68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 19));
    // 0x148e6c: 0xad0f0000  sw          $t7, 0x0($t0)
    ctx->pc = 0x148e6cu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 15));
    // 0x148e70: 0xad230000  sw          $v1, 0x0($t1)
    ctx->pc = 0x148e70u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 3));
    // 0x148e74: 0xad4c0000  sw          $t4, 0x0($t2)
    ctx->pc = 0x148e74u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 12));
    // 0x148e78: 0x8fa30050  lw          $v1, 0x50($sp)
    ctx->pc = 0x148e78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x148e7c: 0xad6d0000  sw          $t5, 0x0($t3)
    ctx->pc = 0x148e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 0), GPR_U32(ctx, 13));
    // 0x148e80: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x148e80u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x148e84: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x148e84u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x148e88: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x148e88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x148e8c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x148e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x148e90: 0x3e00008  jr          $ra
    ctx->pc = 0x148E90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148E90u;
            // 0x148e94: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x148E98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
